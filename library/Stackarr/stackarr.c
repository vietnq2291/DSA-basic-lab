#include<stdio.h>
#include"stackarr.h"

int top;

void initialize(StackType stack){
    top = 0;
}

int is_empty(StackType stack){
    return (top == 0);
}

int is_full(StackType stack){
    return (top == MAX);
}

void push(ElementType e, StackType stack){
    if (is_full(stack))
        printf("Stack overflow\n");
    else
        stack[top++] = e;
}

ElementType pop(StackType stack){
    if (is_empty(stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return stack[--top];
}

ElementType peek(StackType stack){
    if (is_empty(stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return stack[top - 1];
}
