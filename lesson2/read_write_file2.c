#include<stdio.h>
#include<ctype.h>
const int MAX_LEN = 81;

int main(){
    FILE *fr, *fw;
    char fr_name[]="lab2.txt",
         fw_name[]="lab2w.txt";

    if ((fr = fopen(fr_name, "r")) == NULL){
        printf("Cannot open file %s\n", fr_name);
    } else if ((fw = fopen(fw_name, "w")) == NULL){
        printf("Cannot open file %s\n", fw_name);
    } else {
        char buff[MAX_LEN];

        // copy content of fr to fw
        while (fgets(buff, MAX_LEN, fr) != NULL){
            fputs(buff, fw);
        }
    }

    return 0;
}
