#include <stdio.h>

typedef struct {
    int N1, N2;
    double V1, I1;
} Xfmr; 

void print(Xfmr t, char *msg){
    printf("\n%s\n", msg);
    printf("N1: %d, N2: %d, V1: %.2f, I1: %.2f\n", t.N1, t.N2, t.V1, t.I1);
    printf("V2: %.2f, I2: %.2f\n", t.V1 * t.N2 / t.N1, t.I1 * t.N1 / t.N2); 
}

int main(){
    Xfmr t;
    double v2;
    
    printf("Enter N1, N2, V1, I1: ");
    scanf("%d %d %lf %lf", &t.N1, &t.N2, &t.V1, &t.I1);
    print(t, "Initial transformer details:");
    
    printf("\nEnter desired V2: ");
    scanf("%lf", &v2);
    t.N1 = t.V1 * t.N2 / v2;
    print(t, "After setting N1 for desired V2:");
    
    return 0;
}
