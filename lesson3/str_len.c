/* 
Read a file using fscanf() 
then print content and length using fprintf() into another file
*/

#include<stdio.h>
#include<string.h>

enum {SUCCESS, FAIL, MAX_LEN = 80};

int main(){
    FILE *fin, *fout;
    int reval = SUCCESS;
    char fin_name[] = "input_strlen.txt",
         fout_name[] = "output_strlen.txt";

    // read files
    if ((fin = fopen(fin_name, "r")) == NULL){
        printf("Cannot open %s.\n", fin_name);
        reval = FAIL;
    } else if ((fout = fopen(fout_name, "w")) == NULL){
        printf("Cannot open %s.\n", fout_name);
        reval = FAIL;
    } else {
        char str[MAX_LEN + 1];
        int len=0;

        while (fgets(str, MAX_LEN, fin)){
            len += strlen(str);
            fprintf(fout, "%s", str);
        }
        fprintf(fout, "\n%d", len);
        
        fclose(fin);
        fclose(fout);
    }

    return reval;
}