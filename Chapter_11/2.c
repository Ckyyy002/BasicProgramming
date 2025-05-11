#include <stdio.h>

int main(){
    FILE *f1, *f2, *fout;
    char ch;

    f2 = fopen("file2.txt", "r");
    if(f2 == NULL){
        printf("Error, there's no file2.txt\n");
        return 1;
    }

    f1 = fopen("file1.txt", "r");
    if(f1 == NULL){
        printf("Error, there's no file1.txt\n");
        fclose(f2);
        return 1;
    }

    fout = fopen("merged.txt", "w");
    if(fout == NULL){
        printf("Error, can't create merged.txt\n");
        fclose(f1);
        fclose(f2);
        return 1;
    }

    while((ch = fgetc(f2)) != EOF){
        fputc(ch, fout);
    }
    fputc('\n', fout);

    while((ch = fgetc(f1)) != EOF){
        fputc(ch, fout);
    }

    fclose(f1);
    fclose(f2);
    fclose(fout);

    return 0;
}
