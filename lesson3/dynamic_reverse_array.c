#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *p;

    // get total number of integers
    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    // allocate memory for n integers
    p = (int *) malloc(n * sizeof(int));
    if (p == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get array of integers from user input
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    printf("Reversed order: ");
    for (int i = n-1; i >= 0; i--){
        printf("%d ", p[i]);
    }
    printf("\n");
    
    free(p);
    return 0;
}