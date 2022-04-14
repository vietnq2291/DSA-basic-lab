#include<stdio.h>

int main(int argc, char* argv[]){
    int n = argc - 1;

    for (int i = n; i > 0; i--){
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}
