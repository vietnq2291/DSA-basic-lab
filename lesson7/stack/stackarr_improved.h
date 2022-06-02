#include<stdio.h>
#define MAX 50

typedef int EleType;
typedef struct StackRec{
    EleType storage[MAX];
    int top;
};
typedef struct StackRec StackType;
int top;

void initalize(StackType *stack){
    (*stack).top = 0;
}

int is_empty(StackType stack){
    return (stack.top == 0);
}

int is_full(StackType stack){
    return (top == MAX);
}

void push(EleType e, StackType *stack){
    if (is_full(*stack))
        printf("Stack overflow\n");
    else
        (*stack).storage[(*stack).top++] = e;
}

EleType pop(StackType *stack){
    if (is_empty(*stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return (*stack).storage[--(*stack).top];
}

EleType peek(StackType stack){
    if (is_empty(stack)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return stack.storage[top - 1];
}

