#include<stdio.h>
#include<stdlib.h>

void get_number(int *p, int n){
    printf("Enter %d number: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
}

void print_reverse(int *p, int n){
    for (int i = n-1; i >= 0; i--){
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);

    p = (int *) malloc(n * sizeof(int));

    if (p == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    get_number(p, n);
    print_reverse(p, n);
    free(p);
    return 0;
}
