#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Wrong number of parameters.\nThe correct syntax is: word_rep <word> <rep. number>\n");
    } else {
        for (int i = 0; i < atoi(argv[2]); i++){
            printf("%s", argv[1]);
        }
        printf("\n");
    }
    return 0;
}
