#include<stdio.h>

void copy_file(FILE *fsrc, FILE *fdest){
    char c;

    while ((c = fgetc(fsrc)) != EOF){
        fputc(c, fdest);
    }
}

int main(int argc, char* argv[]){
    FILE *fsrc, *fdest;

    if (argc != 3){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: mycp <filepath 1> <filepath 2>\n");
    } else if ((fsrc = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file %s\n", argv[1]);
    } else if ((fdest = fopen(argv[2], "w")) == NULL){
        printf("Cannot open file %s\n", argv[2]);
    } else {
        copy_file(fsrc, fdest);
        printf("Content of %s is successfully copied to %s\n.", argv[1], argv[2]);
    }
    return 0;
}
