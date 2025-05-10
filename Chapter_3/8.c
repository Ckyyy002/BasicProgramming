#include <stdio.h>
#include <math.h>

float convert_speed(float x){
    float z = x * 0.44704;
    return z;
}

float convert_time(float y){
    float w = y * 60;
    return w;
}

void calculate(float vi, float vf, float t){
    float speed = vf - vi;
    float a = speed / t;
    float i = fabs(vi / a);
        if (a >= 0) {
            a = fabs(a);
            printf("The acceleration of the train is %.2f m/s^2", a);
        }
        else {
            printf("The deceleration of the train is %.2f m/s^2\n", a);
            printf("The time taken before the train stop is %.2f second", i);
        }
}

int main(){
    float a, b, c, d, e, f;

    printf("Enter the initial speed of the train (mil/hr): ");
    scanf("%f", &a);
    d = convert_speed(a);

    printf("Enter the final speed of th train (mil/hr): ");
    scanf("%f", &b);
    e = convert_speed(b);

    printf("Enter the time interval for the train to rest (minute): ");
    scanf("%f", &c);
    f = convert_time(c);

    calculate(d, e, f);

    return 0;
}
