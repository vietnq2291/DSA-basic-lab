#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100
#define WORD_SIZE 50
#define MAX_WORDS 100

typedef struct
{
    int id, price;
    char name[WORD_SIZE];
} product;

int main()
{
    FILE *fin;
    char str[MAX_WORDS];
    product pd[MAX_LEN];
    int i=0;

    if ((fin = fopen("product_list.txt", "r")) == NULL)
    {
        printf("File not found");
    } else {
        printf("ID\tName\t\t\tPrice\n");

        while (fscanf(fin, "%d %s %d", &pd[i].id, pd[i].name, &pd[i].price) != EOF){
            printf("%d\t%s\t%d\n", pd[i].id, pd[i].name, pd[i].price);
            i++;
        }
    }
    fclose(fin);
    return 0;
}