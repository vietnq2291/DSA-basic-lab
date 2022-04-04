#include<stdio.h>
#include<ctype.h>

void ReadWriteFile(FILE *fin, FILE *fout){
    int c;

    while ((c = fgetc(fin)) != EOF){
        if (isupper(c)){
            c = tolower(c);
        } else if (islower(c)){
            c = toupper(c);
        }
        fputc(c, fout);
        printf("%c", c);
    }
}

int main(){
    FILE *fin, *fout;
    char filename_in[] = "lab1.txt",
         filename_out[] = "lab1w.txt";

    if ((fin = fopen(filename_in, "r")) == NULL){
        printf("Cannot open %s\n", filename_in);
    } else if ((fout = fopen(filename_out, "w")) == NULL){
        printf("Cannot open %s\n", filename_out);
    } else {
        ReadWriteFile(fin, fout);
        fclose(fin);
        fclose(fout);
    };


    return 0;
}
