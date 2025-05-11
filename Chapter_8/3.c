#include <stdio.h>
#include <string.h>
int i;

void fact(char *out, int n){
    int res = 1;
    char buf[10];

    sprintf(out, "%d! = ", n);

    if (n == 0) {
        strcat(out, "1");
    } else {
        for(i = n; i > 0; i--){
            res *= i;
            sprintf(buf, "%d", i);
            strcat(out, buf);

            if(i > 1) {
                strcat(out, " x ");
            }
        }
    }
    
    sprintf(buf, " = %d", res);
    strcat(out, buf);
}

void print_box(char *str) {
    int len = strlen(str);
    
    for(i = 0; i < len + 4; i++){
        printf("*");
    }

    printf("\n");
    printf("* %s *\n", str);
    
    for(i = 0; i < len + 4; i++){
        printf("*");
    }

    printf("\n");
}

int main(){
    int n;
    char out[100];
    
    while(1){
        printf("Enter an integer between 0 and 9 or -1 to quit => ");
        scanf("%d", &n);
        
        if(n == -1){
            break;
        }
        if(n < 0 || n > 9){
            printf("Invalid entry\n");
            continue;
        }
        
        fact(out, n);
        print_box(out);
    }
    
    return 0;
}
