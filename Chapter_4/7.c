#include <stdio.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int day_number(int month, int day, int year) {
    const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = day;
    
    if (month > 2 && is_leap_year(year)) {
        total_days += 1; 
    }
    
    for (int m = 1; m < month; m++) {
        total_days += days_in_month[m];
    }
    
    return total_days;
}

int main() {
    int month, day, year;
    
    printf("Enter the month in number: ");
    scanf("%d", &month);
    printf("Enter the date: ");
    scanf("%d", &day);
    printf("Enter the year: ");
    scanf("%d", &year);

    printf("The day number is %d", day_number(month, day, year));
    
    return 0;
}
