#include <stdio.h>

int main(){
    double thisYear[12], lastYear[12], totalThisYear = 0, totalLastYear = 0;
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter the rainfall data (this year, last year) for each month:\n");

    for(int i = 0; i < 12; i++){
        scanf("%lf %lf", &thisYear[i], &lastYear[i]);
        totalThisYear += thisYear[i];
        totalLastYear += lastYear[i];
    }

    printf("    Table of monthly rainfall\n");
    printf("          ");
    for(int i = 0; i < 12; i++) {
        printf("%-9s", months[i]);
    }
    
    printf("\nThis year ");
    for(int i = 0; i < 12; i++){
        printf("%-9.1lf", thisYear[i]);
    }

    printf("\nLast year ");
    for (int i = 0; i < 12; i++) {
        printf("%-9.1lf", lastYear[i]);
    }

    printf("\nTotal rainfall this year: %.1lf\n", totalThisYear);
    printf("Total rainfall last year: %.1lf\n", totalLastYear);
    printf("Average monthly rainfall for this year: %.1lf\n", totalThisYear / 12);
    printf("Average monthly rainfall for last year: %.1lf\n", totalLastYear / 12);

    return 0;
}
