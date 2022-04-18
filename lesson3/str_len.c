#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

int main()
{
    FILE *fin, *fout;
    char str[MAX_LEN];
    int len;

    if ((fin = fopen("input.txt", "r")) == NULL)
    {
        printf("File not found");
    } else if ((fout = fopen("output.txt", "w")) == NULL){
        printf("File not found");
    } else {
        while (fgets(str, MAX_LEN, fin) != NULL)
        {
            len = strlen(str) - 1;
            fprintf(fout, "%d %s\n", len, str);
            printf("%s", str);
        }
    }
    return 0;
}