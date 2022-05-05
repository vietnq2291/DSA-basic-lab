#include<stdio.h>
#define MAX_LEN 80

void merge_file(FILE *fin1, FILE *fin2, FILE *fout){
    char buff1[MAX_LEN],
         buff2[MAX_LEN];
    int len;

    while ((fgets(buff1, MAX_LEN, fin1) != NULL) && (fgets(buff2, MAX_LEN, fin2) != NULL)){
        fputs(buff1, fout);
        fputs(buff2, fout);
    }
    if (buff1 != NULL) fputs(buff1, fout);

    while (fgets(buff1, MAX_LEN, fin1) != NULL){
        fputs(buff1, fout);
    }
    while (fgets(buff2, MAX_LEN, fin2) != NULL){
        fputs(buff2, fout);
    }
}

int main(int argc, char* argv[]){
    FILE *fin1, *fin2, *fout;

    if (argc != 4){
        printf("The correct syntax is: merge file1 file2 file3\n");
        return 1;
    }

    // Read file
    if ((fin1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    } else if ((fin2 = fopen(argv[2], "r")) == NULL){
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    } else if ((fout = fopen(argv[3], "w")) == NULL){
        printf("Cannot open file %s\n", argv[3]);
        return 1;
    }

    merge_file(fin1, fin2, fout);

    return 0;
}
