#include<stdio.h>
enum {SUCCESS, FAIL, MAX_ELEMENT=10};

typedef struct
{
    int no;
    char name[20];
    double price;
} product;

int main(void){
    FILE *fp;
    product arr[MAX_ELEMENT];
    int n, i=0;
    int reval = SUCCESS;
    printf("Loading file...\n");
    if ((fp=fopen("product_list.txt")))

}