#include <stdio.h>
#include <string.h>

void one_ele_subs(char str[]){
    printf("\nOne-element subsets:\n");
    for (int i = 0; str[i]; i++){
        printf("{%c}\n", str[i]);
    }
}

void two_ele_subs(char str[]){
    printf("\nTwo-element subsets:\n");
    for (int i = 0; str[i]; i++){
        for (int j = i + 1; str[j]; j++){
            printf("{%c, %c}\n", str[i], str[j]);
        }
    }
}

void three_ele_subs(char str[]){
    printf("\nThree-element subsets:\n");
    for (int i = 0; str[i]; i++) {
        for (int j = i + 1; str[j]; j++) {
            for (int k = j + 1; str[k]; k++) {
                printf("{%c, %c, %c}\n", str[i], str[j], str[k]);
            }
        }
    }
}

int main() {
   char input[100];
    
    printf("Input string: ");
    scanf("%s", &input);
    
    one_ele_subs(input);
    two_ele_subs(input);
    three_ele_subs(input);
    
    return 0;
}
