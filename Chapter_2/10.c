#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double y0, x0, x1, y1, x2, y2; 
    double m, xt, yt, c; 

    printf("Input the coordinate of the first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Input the coordinate of the second point: ");
    scanf("%lf %lf", &x2, &y2);

    if (x1 != x2) {
        m = (y2 - y1) / (x2 - x1);
        m = -1 / m;
        xt = (x1 + x2) / 2;
        yt = (y1 + y2) / 2;
        c = yt - m * xt;
        x0 = -c / m;
        y0 = yt - m * xt;

        printf("The coordinate of the first point is: (%.1lf, %.1lf)\n", x1, y1);
        printf("The coordinate of the second point is: (%.1lf, %.1lf)\n", x2, y2);
        printf("The equation of the perpendicular line between both points is y = %.2fx + %.2f\n", m, c);
    }
    else {
        printf("The line between both points is vertical or the slope is infinite\n");
    }

    return 0;
}
