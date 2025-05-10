#include <stdio.h>
#include <math.h>

float speeds_ratio(float M, float m){
    int a = M / m;
    return pow(a, 0.2);
}

int main(){
    float M, m;

    printf("Input the maximum speed of a six-speed gearbox in rpm: ");
    scanf("%f", &M);
        if (M <= 0) {
            printf("Input the maximum speed greater than 0!\n");
        }

    printf("Input the minimum speed of a six-speed gearbox in rpm: ");
    scanf("%f", &m);
        if (m <= 0) {
            printf("Input the minimum speed greater than 0!\n");
        }

    float ratio = speeds_ratio(M, m);
    
    printf("The ratio between successive speeds of a six-speed gearbox with maximum speed %.1f rpm and minimum speed %.1f rpm is %.2f", M, m, ratio);

    return 0;
}
