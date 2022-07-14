#include<stdio.h>
#include<stdlib.h>
#include"stacklist.h"

StackType top = NULL;

int main(){
    int a[6] = {1,2,3,5,7,9};
    
    printf(is_empty(top)? "empty\n":"Not empty\n");

    for (int i=0; i<6; i++) {
        push(a[i], &top);
    }
    printf("Pop all elements in stack!\n");
    while (!is_empty(top)) {
        printf("peak: %d\n", peek(top));
        printf("%4d\n", pop(&top));
    }

    printf("peak: %d\n", peek(top));

    return 0;
}
