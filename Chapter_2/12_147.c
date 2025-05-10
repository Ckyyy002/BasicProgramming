#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double v, s, a, t;
    printf("Input the jet's takeoff speed (km/hr): ");
    scanf("%lf", &v);
    printf("Input the distance traveled by the jet (m): ");
    scanf("%lf", &s);

    v = (v*1000)/3600;
    t = 2*s/v;
    a = v/t;

    printf("The jet's acceleration was %.2lf m/s^2\n", a);
    printf("Time spent by the jet was %.2lf s\n", t);
    return 0;
}