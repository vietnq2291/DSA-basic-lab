#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);

    p = (int *) malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Get the numbers from the user
    for (int i = 0; i < n; i++){
        scanf("%d", p+i);
    }

    // Display them in reverse
    for (int i = n-1; i >= 0; i--){
        printf("%d ", *(p+i));
    }
    printf("\n");
    free(p);
    return 0;
}
