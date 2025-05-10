#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum { S, B_NUM, B_ID, NUM, ID, STOP } State;

State trans(State s, char c) {
    if(s == S){
        return isdigit(c) ? B_NUM : (isalpha(c) ? B_ID : STOP);
    }
    if(s == B_NUM){
        return isdigit(c) ? B_NUM : NUM;
    }
    if(s == B_ID){
        return isalnum(c) ? B_ID : ID;
    }
    return STOP;
}

int main() {
    char in[256], token[256], *p = in;
    State s = S;

    fgets(in, sizeof(in), stdin);
    in[strcspn(in, "\n")] = 0; 

    while(*p){
        int i = 0;
        while(*p == ' ') {
            p++;
        }

        while(*p && *p != ' '){
            token[i++] = *p++;
            s = trans(s, token[i-1]);
        }

        token[i] = '\0'; 

        if(s == B_NUM){
            printf("%s - Number\n", token);
        }
        else if(s == B_ID){
            printf("%s - Identifier\n", token);
        }

        s = S; 
    }

    return 0;
}
