#include<stdio.h>

int main(){
    FILE *fr, *fw;
    char fr_name[]="lab1.txt",
         fw_name[]="lab1w.txt";

    if ((fr = fopen(fr_name, "r")) == NULL){
        printf("Cannot open file %s\n", fr_name);
    } else if ((fw = fopen(fw_name, "w")) == NULL){
        printf("Cannot open file %s\n", fw_name);
    } else {
        char c;

        // copy content of fr to fw
        while ((c = fgetc(fr)) != EOF){
            fputc(c, fw);
        }
    }

    return 0;
}
