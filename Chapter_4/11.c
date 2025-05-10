#include <stdio.h>

int within_x_percent(float ref, float data, float x) {
    float min = ref - (x / 100) * ref;
    float max = ref + (x / 100) * ref;
    return (min <= data && data <= max);
}

float identify_substance(float temp) {
    float water = 100;
    float mercury = 357;
    float copper = 1187;
    float silver = 2193;
    float gold = 2660;

    if (within_x_percent(water, temp, 5)) {
        return 1;
    } else if (within_x_percent(mercury, temp, 5)) {
        return 2;
    } else if (within_x_percent(copper, temp, 5)) {
        return 3;
    } else if (within_x_percent(silver, temp, 5)) {
        return 4;
    } else if (within_x_percent(gold, temp, 5)) {
        return 5;
    } else {
        return 0;
    }
}

int main() {
    float substance;

    printf("Enter the observed boiling point: ");
    scanf("%f", &substance);

    float result = identify_substance(substance);

    if(result == 0){
        printf("Substance unknown");
    }
    else if(result == 1){
        printf("Substance is water");
    }
    else if(result == 2){
        printf("Substance is mercury");
    }
    else if(result == 3){
        printf("Substance is copper");
    }
    else if(result == 4){
        printf("Substance is silver");
    }
    else if(result == 5){
        printf("Substance is gold");
    }

    return 0;
}
