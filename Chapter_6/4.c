#include <stdio.h>

int get_q() {
    int q;
    printf("Select the form (1 or 2):\n1) Two-point form\n2) Point-slope form\n=> ");
    scanf("%d", &q);
    return q;
}

void get_2pts(double *x1, double *y1, double *x2, double *y2) {
    printf("Enter x1 and y1 => ");
    scanf("%lf %lf", x1, y1);
    printf("Enter x2 and y2 => ");
    scanf("%lf %lf", x2, y2);
}

void get_pt_slope(double *m, double *x1, double *y1) {
    printf("Enter slope => ");
    scanf("%lf", m);
    printf("Enter x y => ");
    scanf("%lf %lf", x1, y1);
}

void calc_2pts(double x1, double y1, double x2, double y2, double *m, double *b) {
    *m = (y2 - y1) / (x1 - x2);
    *b = y1 - (*m * x1);
}

double calc_pt_slope(double m, double x1, double y1) {
    return y1 - m * x1;
}

void show_2pts(double x1, double y1, double x2, double y2) {
    printf("Two-point form:\nm = (%.2f - %.2f) / (%.2f - %.2f)\n", y2, y1, x2, x1);
}

void show_pt_slope(double m, double x1, double y1) {
    printf("Point-slope form:\ny - %.2f = %.2f(x - %.2f)\n", y1, m, x1);
}

void show_slope_int(double m, double b) {
    printf("Slope-intercept form:\ny = %.2fx + %.2f\n", m, b);
}

int main() {
    char again = 'Y';
    while (again == 'Y' || again == 'y') {
        int opt = get_q();
        double x1, y1, x2, y2, m, b;

        if (opt == 1) {
            get_2pts(&x1, &y1, &x2, &y2);
            show_2pts(x1, y1, x2, y2);
            calc_2pts(x1, y1, x2, y2, &m, &b);
        } 
        else {
            get_pt_slope(&m, &x1, &y1);
            show_pt_slope(m, x1, y1);
            b = calc_pt_slope(m, x1, y1);
        }

        show_slope_int(m, b);
        printf("Do again (Y/N)? ");
        scanf(" %c", &again); 
    }
    return 0;
}
