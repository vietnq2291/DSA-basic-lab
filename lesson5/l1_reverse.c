#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, sum=0;
    int *ptr;
    FILE *fout;
    char filename[] = "out.txt";

    // get input
    printf("Length of array: "); scanf("%d", &n);

    // allocate memory for n elements
    ptr = (int *) malloc(n * sizeof(int));
    if (ptr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    // get array input
    printf("Enter array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    // open file
    if ((fout = fopen(filename, "w")) == NULL){
        printf("Cannot open %s.\n", filename);
        return 1;
    }

    // write reverse array into file
    for (int i = n-1; i >= 0; i--){
        fprintf(fout, "%d ", ptr[i]);
        sum += ptr[i];
    }
    fprintf(fout, "%d\n", sum);

    // close file and free memory location
    fclose(fout);
    free(ptr);
    return 0;
}
