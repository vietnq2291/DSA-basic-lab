#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 100

char* subStr(char* s1, int off_set, int number){
    char *s2;

    s2 = (char *) malloc((number + 1) * sizeof(char));

    if (s2 == NULL){
        printf("Allocation failed! Check memory\n");
        return NULL;
    }
    for (int i = 0; i < number; i++){
        //.....................
    }
    return s2;
}

int main(){
    FILE *fin, *fout;
    char fin_name[] = "input3.txt",
         fout_name[] = "output3.txt";
    char s1[MAX_LEN];

    if ((fin = fopen(fin_name, "r")) == NULL){
        printf("Cannot open file %s\n", fin_name);
        return 1;
    } else if ((fout = fopen(fout_name, "w")) == NULL){
        printf("Cannot open file %s\n", fout_name);
        return 1;
    }

    // Read content from input file
    fscanf(fin, "%[^\n]s", s1);
    printf("substring: %s\n", subStr(s1, 1, 3));

    return 0;
}
