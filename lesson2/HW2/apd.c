#include<stdio.h>

void append_file(FILE *fsrc, FILE *fadd){
    char c;

    while ((c = fgetc(fadd)) != EOF){
        fputc(c, fsrc);
    }
}

int main(int argc, char* argv[]){
    FILE *fsrc, *fadd;

    if (argc != 3){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: apd <filepath 1> <filepath 2>\n");
    } else if ((fsrc = fopen(argv[1], "a")) == NULL){
        printf("Cannot open file %s\n", argv[1]);
    } else if ((fadd = fopen(argv[2], "r")) == NULL){
        printf("Cannot open file %s\n", argv[2]);
    } else {
        append_file(fsrc, fadd);
        printf("Content of %s is successfully appended to the end of %s\n", argv[2], argv[1]);
    }
    return 0;
}
