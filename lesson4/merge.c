#include<stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};

void merge_file(FILE *fin1, FILE *fin2, FILE *fout){
    char buff1[MAX_LEN + 1],
         buff2[MAX_LEN + 1];

    // Read from 2 file and write simutaneously
    while (fgets(buff1, MAX_LEN, fin1) != NULL && fgets(buff2, MAX_LEN, fin2) != NULL){
        fputs(buff1, fout);
        fputs(buff2, fout);
    }

    // print last read buffer from fin1 if fin2 ends earlier
    if (buff1 != NULL){
        fputs(buff1, fout);
    }

    // Read from 1 file only and write
    while (fgets(buff1, MAX_LEN, fin1) != NULL){
        fputs(buff1, fout);
    }
    while (fgets(buff2, MAX_LEN, fin2) != NULL){
        fputs(buff2, fout);
    }
}

int main(int argc, char* argv[]){
    int reval = SUCCESS;
    FILE *fin1, *fin2, *fout;

    // check number of arguments
    if (argc != 4){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: merge <file1> <file2> <file3>\n");
    } else if ((fin1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } else if ((fin2 = fopen(argv[2], "r")) == NULL){
        printf("Cannot open %s.\n", argv[2]);
        reval = FAIL;
    } else if ((fout = fopen(argv[3], "w")) == NULL){
        printf("Cannot open %s.\n", argv[3]);
        reval = FAIL;
    } else {
        merge_file(fin1, fin2, fout);
    }

    return reval;
}