#include <stdio.h>
#include <math.h>

int main() {
    float fixed_weekday = 600, base_cents = 3999, extra_cents_rate = 40, tax_rate = 5.25;
    int weekday, night, weekend;

    printf("Enter the number of weekday minutes used: ");
    scanf("%d", &weekday);
    printf("Enter the number of night minutes used: ");
    scanf("%d", &night);
    printf("Enter the number of weekend minutes used: ");
    scanf("%d", &weekend);

    printf("Weekday minutes spent is %d minutes\n", weekday);
    printf("Night minutes spent is %d minutes\n", night);
    printf("Weekend minutes spent is %d minutes\n", weekend);

    float extra_minutes = 0, cost = 0;    

    if (weekday > fixed_weekday) {
        extra_minutes = weekday - fixed_weekday;
    } 
    else {
        extra_minutes = 0;
    }

    float charge = (extra_minutes * extra_cents_rate);

    float pretax_bill = (base_cents + charge);
    printf("The pretax bill is $%.2f\n", pretax_bill / 100);

    float taxes = round(pretax_bill * tax_rate / 100);
    printf("The tax is $%.2f\n", taxes / 100);

    float total_minutes = weekday + night + weekend;

    if (total_minutes > 0) {
        cost = pretax_bill / total_minutes;
    } 
    else {
        cost = 0;
    }

    printf("The average minute cost is $%.2f\n", cost / 100);

    float total_bill = (pretax_bill + taxes);
    printf("The total bill is $%.2f\n", total_bill / 100);

    return 0;
}
