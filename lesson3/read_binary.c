#include<stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};

int main(){
    int reval = SUCCESS;
    int num;
    FILE *fptr;
    char filename[] = "haiku.txt";
    char buff[MAX_LEN + 1];

    // open file
    if ((fptr = fopen(filename, "rb")) == NULL){
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        num = fread(buff, sizeof(char), MAX_LEN, fptr);
        buff[num * sizeof(char)] = '\0';
        printf("%s\n", buff);
        printf("Number of character actually read: %d\n", num);

        fclose(fptr);
    }
    return reval;
}