#include <stdio.h>
#include <string.h>

void extractU(char *inputf, char *outputf){
    FILE *input = fopen(inputf, "r");
    if(input == NULL){
        printf("File Not Found %s\n", inputf);
        return;
    }

    FILE *output = fopen(outputf, "w");
    if(output == NULL){
        printf("File Not Found %s\n", outputf);
        fclose(input);
        return;
    }

    char ch;
    while((ch = fgetc(input)) != EOF){
        if(ch >= 'A' && ch <= 'Z'){
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);
    printf("File containing only uppercase letters has been built within the name of %s\n", outputf);
}

void extractA(char *inputf,  char *outputf){
    char line[256];

    FILE *input = fopen(inputf, "r");
    if(input == NULL){
        printf("File Not Found %s\n", inputf);
        return;
    }

    FILE *output = fopen(outputf, "w");
    if(output == NULL){
        printf("File Not Found %s\n", outputf);
        fclose(input);
        return;
    }

    while(fgets(line, 256, input) != NULL){
        if(line[0] == 'A' || line[0] == 'a'){
            fputs(line, output);
        }
    }

    fclose(input);
    fclose(output);
    printf("File containing only A/a started lines has been built within the name of %s\n", outputf);
}

int main(){
    int choice;
    char *inputf = "input.txt";   
    char *outputf = "output.txt";  

    printf("Select an option:\n");
    printf("1. Extract uppercase letters\n");
    printf("2. Extract lines starting with 'A'\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1){
        extractU(inputf, outputf);
    } 
    else if(choice == 2){
        extractA(inputf, outputf);
    } 
    else{
        printf("Invalid choice! -__-\n");
    }

    return 0;
}
