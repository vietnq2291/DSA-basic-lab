#include<stdio.h>
#include "stackarr.h"

int main(){
    int a[6] = {1,2,3,5,7,9};
    StackType s; 
    
    initialize(s);

    for (int i=0; i<5; i++)
        push(a[i], s);

    printf("Pop all elements in stack!\n");
    while (!is_empty(s)) {
        printf("%4d\n", pop(s));
    }

    return 0;
}
