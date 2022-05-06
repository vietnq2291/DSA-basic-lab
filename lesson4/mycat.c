#include<stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};

void BlockCat(FILE *fptr){
    char buff[MAX_LEN + 1];
    int count;

    while (!feof(fptr)){
        count = fread(buff, sizeof(char), MAX_LEN, fptr);
        buff[count * sizeof(char)] = '\0';
        printf("%s", buff);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    FILE *fptr;
    int reval = SUCCESS;

    
    // check arguments condition
    if (argc != 2){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: mycat <filename>\n");
        reval = FAIL;
    } else if ((fptr = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } else {
        BlockCat(fptr);
        fclose(fptr);
    }

    return reval;
}