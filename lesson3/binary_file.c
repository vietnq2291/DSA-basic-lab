#include<stdio.h>

int main(){
    enum{MAX_LEN = 80};
    int num;
    FILE *fin, *fout;
    char filename1[] = "lab1.txt",
         filename2[] = "lab2.txt";
    
    if ((fin = fopen(filename1, "rb")) == NULL){
        printf("File not found");
    } else if ((fout = fopen(filename2, "wb")) == NULL){
        printf("File not found");
    } else {
        char *buff;
        fread(buff, sizeof(char), MAX_LEN, fin);
        printf("%s", buff);
    }

    return 0;
}