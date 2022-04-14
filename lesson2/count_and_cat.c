#include<stdio.h>
#include<ctype.h>
const int MAX_LEN = 80;

int main(){
    FILE *fptr;
    char filename[]="lab2.txt";

    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open file %s\n", filename);
    } else {
        char buff[MAX_LEN];
        int count=0;

        printf("Reading file %s... done!\n\n", filename);
        while (fgets(buff, MAX_LEN, fptr) != NULL){
            printf("%s", buff);
            count++;
        }
        printf("\nThis file has %d lines.\n", count);
    }

    return 0;
}
