#include <stdio.h>

int main(){
    int a, sign = 1;
    double pi = 0;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        pi += sign * (1.0 / (2 * i + 1));
        sign = -sign;
    }

    pi *= 4;
    printf("%lf", pi);

    return 0;
}
