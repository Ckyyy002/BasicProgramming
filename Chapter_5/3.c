#include <stdio.h>
#include <math.h>

int main(){
    float principal, interest, loan;
    int payments;

    printf("Enter the loan amount: $");
    scanf("%f", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%f", &interest);
    printf("Enter the total number of payments: ");
    scanf("%d", &payments);

    float balance = principal;
    float monthly_interest = interest / 1200;
    float monthly_payment = round((monthly_interest * principal) / (1 - pow(1 + monthly_interest, -payments)) * 100) / 100;

    for (int month = 1; month <= payments; month++) {
        float interest = balance * monthly_interest;
        loan = monthly_payment - interest;

        if (month == payments) {
            loan = balance;
            monthly_payment = interest + balance;
        }

        interest = round(interest * 100) / 100;
        loan = round(loan * 100) / 100;
        balance = round((balance - loan) * 100) / 100;

        printf("%d\t%.2f\t%.2f\t%.2f\n", month, interest, loan, balance);
    }
    return 0;
}
