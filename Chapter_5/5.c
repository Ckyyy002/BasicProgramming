#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    printf("The GCD is %d\n", a);

    return 0;
}
