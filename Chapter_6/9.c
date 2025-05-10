#include <stdio.h>
#define r 1.23

double calc_drag(double cd, double a, double v){
    return 0.5 * cd * a * r * v * v;
}

int main() {
    double cd, a;

    printf("Enter drag coefficient: ");
    scanf("%lf", &cd);
    printf("Enter area (m^2): ");
    scanf("%lf", &a);

    printf("\nVel (m/s)\tDrag (N)\n------------------------------\n");

    for(int v = 0; v <= 40; v += 5){
        printf("%d\t\t%.2f\n", v, calc_drag(cd, a, v));
    }

    return 0;
}
