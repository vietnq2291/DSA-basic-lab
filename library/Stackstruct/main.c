#include<stdio.h>
#include"stackstruct.h"

int main(){
    int a[6] = {1,2,3,5,7,9};
    StackType s; 
    
    initialize(&s);
    printf("%d\n", s.top);

    for (int i=0; i<6; i++)
        push(a[i], &s);
    printf("peak: %d\n", peek(s));
    printf("Pop all elements in stack!\n");
    while (!is_empty(s)) {
        printf("%4d\n", pop(&s));
    }

    printf("peak: %d\n", peek(s));

    return 0;
}
