#include<stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80, SIZE = 100};

typedef struct product{
    int id, price;
    char name[MAX_LEN];
} product_t;

int main(){
    FILE *fptr;
    product_t pd[SIZE];
    char filename[] = "product.txt";
    int reval = SUCCESS, i = 0;

    // read file
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        int c;
        printf("%-2s\t%-25s\t%-10s\n", "ID", "Name", "Price");

        // get input using scanf():
        // using " , " inside scanf() to skip one character ','
        // using %[^,] to stop reading whenever see a ',' (exclusive)
        while (fscanf(fptr, "%d,%[^,],%d", &pd[i].id, pd[i].name, &pd[i].price) != EOF){
            printf("%-2d\t%-25s\t%-10d\n", pd[i].id, pd[i].name, pd[i].price);
            i++;
        }
        fclose(fptr);
    }

    return reval;
}