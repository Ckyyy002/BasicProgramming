#include <stdio.h>
#include <string.h>

#define MAX_LEN 80

int main() {
    char n[MAX_LEN], sur[MAX_LEN], fir[MAX_LEN], mid[MAX_LEN];

    printf("Enter a name: ");
    fgets(n, MAX_LEN, stdin);
    n[strcspn(n, "\n")] = '\0';

    char* tok = strtok(n, ",");
    strcpy(sur, tok);

    tok = strtok(NULL, " ");
    for(int i = 0; i < strlen(tok); i++){
        if(tok[i] == '.'){
            tok[i] = '\0';  
        }
    }
    strcpy(fir, tok);

    tok = strtok(NULL, ".");
    strcpy(mid, tok);
    
    printf("%.15s\t\t%.15s\t\t%.15s\n", sur, fir, mid);

    return 0;
}
