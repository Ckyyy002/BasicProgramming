#include <stdio.h>
#define MAX_N 10
#define DIM 3

int get_pm(double loc[MAX_N][DIM], double m[MAX_N]) {
    int n;

    printf("Enter number of points (n): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_N) {
        return 0;
    }

    printf("Enter location matrix (x y z):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DIM; j++) {
            scanf("%lf", &loc[i][j]);
        }
    }

    printf("Enter masses:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &m[i]);
    }

    return n;
}

void cg(double loc[MAX_N][DIM], double m[MAX_N], int n, double c[DIM]) {
    double totalM = 0;
    for (int j = 0; j < DIM; j++) {
        c[j] = 0;
    }

    for (int i = 0; i < n; i++) {
        totalM += m[i];
        for (int j = 0; j < DIM; j++) {
            c[j] += m[i] * loc[i][j];
        }
    }

    for (int j = 0; j < DIM; j++) {
        c[j] /= totalM;
    }
}

int main() {
    double loc[MAX_N][DIM], m[MAX_N], c[DIM];
    int n;

    while ((n = get_pm(loc, m))) {
        printf("Location matrix:\n");
        for (int i = 0; i < n; i++) {
            printf("(%.2lf, %.2lf, %.2lf)\n", loc[i][0], loc[i][1], loc[i][2]);
        }
        printf("Mass vector:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2lf\n", m[i]);
        }
        cg(loc, m, n, c);
        printf("Center of Gravity: (%.2lf, %.2lf, %.2lf)\n\n", c[0], c[1], c[2]);
    }

    return 0;
}
