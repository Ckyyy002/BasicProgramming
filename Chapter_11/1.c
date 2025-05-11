#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int site_id_num;
    int day_of_month;
    int wind_speed;
    int temperature;
} measured_data_t;

void find_temperature_variation(measured_data_t data[], int count, int *site_id, float *variation) {
    float temp_min[10] = {0}, temp_max[10] = {0};
    int site_count[10] = {0};

    for (int i = 0; i < count; i++) {
        int site_slot = data[i].site_id_num % 10;
        if (site_count[site_slot] == 0) {
            temp_min[site_slot] = temp_max[site_slot] = data[i].temperature;
        } else {
            if (data[i].temperature < temp_min[site_slot]) {
                temp_min[site_slot] = data[i].temperature;
            }
            if (data[i].temperature > temp_max[site_slot]) {
                temp_max[site_slot] = data[i].temperature;
            }
        }
        site_count[site_slot]++;
    }

    *variation = 0;
    *site_id = 0;
    for (int i = 0; i < 10; i++) {
        if (site_count[i] > 0) {
            float current_variation = temp_max[i] - temp_min[i];
            if (current_variation > *variation) {
                *variation = current_variation;
                *site_id = i + 2000;
            }
        }
    }
}

void find_highest_avg_wind_speed(measured_data_t data[], int count, int *site_id, float *avg_speed) {
    float wind_sum[10] = {0};
    int site_count[10] = {0};

    for (int i = 0; i < count; i++) {
        int site_slot = data[i].site_id_num % 10;
        wind_sum[site_slot] += data[i].wind_speed;
        site_count[site_slot]++;
    }

    *avg_speed = 0;
    *site_id = 0;
    for (int i = 0; i < 10; i++) {
        if (site_count[i] > 0) {
            float current_avg = wind_sum[i] / site_count[i];
            if (current_avg > *avg_speed) {
                *avg_speed = current_avg;
                *site_id = i + 2000;
            }
        }
    }
}

int main() {
    measured_data_t data[70];
    int count = 0;
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (count < 70 && fscanf(file, "%d %d %d %d", 
           &data[count].site_id_num, 
           &data[count].day_of_month, 
           &data[count].wind_speed, 
           &data[count].temperature) == 4) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Error: No data read from file.\n");
        return 1;
    }

    int temp_site_id, wind_site_id;
    float max_temp_variation, max_avg_wind_speed;

    find_temperature_variation(data, count, &temp_site_id, &max_temp_variation);
    find_highest_avg_wind_speed(data, count, &wind_site_id, &max_avg_wind_speed);

    printf("Site with greatest temperature variation: %d (Variation: %.2f °C)\n", temp_site_id, max_temp_variation);
    printf("Site with highest average wind speed: %d (Average Speed: %.2f knots)\n", wind_site_id, max_avg_wind_speed);

    return 0;
}
