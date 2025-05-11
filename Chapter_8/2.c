#include <stdio.h>
#include <string.h>

const char* COL[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
const int NUM_COL = 10;

int find(const char* list[], int size, const char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

int power_of_10(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 10;
    }
    return result;
}

int main() {
    char b1[10], b2[10], b3[10];
    int d1, d2, mult;
    char ans;

    do {
        printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
        printf("Type the colors in lowercase letters only.\n");

        printf("Band 1 => ");
        scanf("%s", b1);
        printf("Band 2 => ");
        scanf("%s", b2);
        printf("Band 3 => ");
        scanf("%s", b3);

        d1 = find(COL, NUM_COL, b1);
        d2 = find(COL, NUM_COL, b2);
        mult = find(COL, NUM_COL, b3);

        if(d1 == -1){
            printf("Invalid color: %s\n", b1);
        } 
        else if(d2 == -1){
            printf("Invalid color: %s\n", b2);
        } 
        else if(mult == -1){
            printf("Invalid color: %s\n", b3);
        } 
        else{
            int res = ((d1 * 10 + d2) * power_of_10(mult)) / 1000;
            printf("Resistance value: %d kilo-ohms\n", res);
        }

        printf("Do you want to decode another resistor? (y/n) => ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    return 0;
}
