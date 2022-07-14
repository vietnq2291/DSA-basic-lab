#include<stdio.h>
#include<stdlib.h>
#include"stacklist.h"

StackType top;

int is_empty(StackType top){
    return (top == NULL);
}

void push(ElementType e, StackType *top){
    Node *new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    new->element = e;
    new->next = (*top);
    (*top) = new;
}

ElementType pop(StackType *top){
    if (top == NULL) {
        printf("Stack is empty");
        return -99999;
    }

    ElementType e = (*top)->element;
    Node *temp = *top;
    (*top) = (*top)->next;
    free(temp);
    return e;
}

ElementType peek(StackType top){
    if (is_empty(top)){
        printf("Stack underflow\n");
        return -999999;
    }
    else
        return top->element;
}

