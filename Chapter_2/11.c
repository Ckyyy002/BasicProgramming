#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int m, n, s1, s2, h;
    printf("Input the value of M: ");
    scanf("%ld", &m);
    printf("Input the value of N: ");
    scanf("%ld", &n);

    if (m > n){
        s1 = pow(m, 2) - pow(n, 2);
        s2 = 2 * m * n;
        h = pow(m, 2) + pow(n, 2);
            if (s1 <= 0 || s2 <= 0) {
                printf("The Phytagorean triple can't be found");
            }
            else {
                printf("The length of side 1 is %d\n", s1);
                printf("The length of side 2 is %d\n", s2);
                printf("The length of hypotenuse is %d\n", h);
            }
    }
    else {
        printf("The value of M should be greater than N\n");
    }
    
    return 0;
}
