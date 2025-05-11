#include <stdio.h>
#include <math.h>

typedef struct{
    double m;
    int e;
} sci_t;

sci_t normalize(double x){
    sci_t r = {x, 0};
    while(r.m && r.m < 0.1){ 
        r.m *= 10; r.e--; 
    }
    while(r.m >= 1.0){ 
        r.m /= 10; r.e++; 
    }
    return r;
}

sci_t compute(double a, double b, char op){
    switch(op){
        case '+': 
            return normalize(a + b);
        case '-': 
            return normalize(a - b);
        case '*': 
            return normalize(a * b);
        case '/': 
            return normalize(b ? a / b : 0);
        default: 
            return (sci_t){0, 0};
    }
}

int main(){
    double m1, m2;
    printf("Enter two scientific numbers (e.g., 1.23e4 5.67e-8): ");
    scanf("%le %le", &m1, &m2);

    char *ops = "+-*/";
    char *names[] = {"sum", "difference", "product", "quotient"};
    
    for(int i = 0; i < 4; i++){
        sci_t result = compute(m1, m2, ops[i]);
        printf("%s: %.5fe%d\n", names[i], result.m, result.e);
    }
    return 0;
}
