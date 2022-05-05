#include<stdio.h>
#include<stdlib.h>

enum {SUCCESS, FAIL, MAX_LEN = 80};

void BlocReadWrite(FILE *fin, FILE *fout){
    int count = 0;

    while (feof(fin) == 0){

    }
}

int main(){
    int num;
    FILE *fptr1, *fptr2;
    char filename1[]="lab1.txt",
         filename2[]="lab1a.txt";
    int reval = SUCCESS;

    if ((fptr1 = fopen(filename1, "w")) == NULL){
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    } else {
        BlocReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }

    return 0;
}
