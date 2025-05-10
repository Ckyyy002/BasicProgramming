#include <stdio.h>

float celsius_at_depth(float depth) {
    return 10 * depth + 20;
}

float fahrenheit_at_depth(float celsius) {
    return 1.8 * celsius + 32;
}

int main() {
    float depth;
    printf("Insert the depth inside the earth in km: ");
    scanf("%f", &depth);
    
    float celsius = celsius_at_depth(depth);
    printf("The celcius temperature in %.2f km depth is %.2f C\n", depth, celsius);

    float fahrenheit = fahrenheit_at_depth(celsius);
    printf("The fahrenheit temperature in %.2f km depth is %.2f F\n", depth, fahrenheit);

    return 0;
}
