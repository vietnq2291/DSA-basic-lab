#include<stdio.h>
#include"stackstruct.h"

StackType stack;

void initialize(StackType *stack){
    (*stack).top = 0;
}

int is_empty(StackType stack){
    return (stack.top == 0);
}

int is_full(StackType stack){
    return (stack.top == MAX);
}

void push(ElementType e, StackType *stack){
    if (is_full(*stack))
        printf("Stack overflow\n");
    else
        (*stack).storage[(*stack).top++] = e;
}

ElementType pop(StackType *stack){
    if (is_empty(*stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return (*stack).storage[--(*stack).top];
}

ElementType peek(StackType stack){
    if (is_empty(stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return stack.storage[stack.top - 1];
}

