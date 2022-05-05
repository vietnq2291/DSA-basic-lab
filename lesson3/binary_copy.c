#include<stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};

void BlockReadWrite(FILE *fin, FILE *fout){
    char buff[MAX_LEN + 1];
    int count;

    while (!feof(fin)){        
        count = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[count * sizeof(char)] = '\0';
        printf("read %d characters\n", count);
        fwrite(buff, sizeof(char), count, fout);
    }
}

int main(){
    int reval = SUCCESS;
    FILE *fin, *fout;
    char fin_name[] = "lab1.txt",
         fout_name[] = "lab1a.txt";

    // open files to read and write
    if ((fin = fopen(fin_name, "rb")) == NULL){
        printf("Cannot open %s.\n", fin_name);
        reval = FAIL;
    } else if ((fout = fopen(fout_name, "wb")) == NULL){
        printf("Cannot open %s.\n", fout_name);
        reval = FAIL;
    } else {
        BlockReadWrite(fin, fout);
        fclose(fin);
        fclose(fout);
    }

    return reval;
}