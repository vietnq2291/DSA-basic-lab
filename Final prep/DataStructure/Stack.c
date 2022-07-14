#include<stdio.h>
#include<stdlib.h>

// define element type & Node -------------------------------------------------
typedef struct{
    // define element type here...
    int num;
} ElementType;

typedef struct Node_t {
    ElementType element;
    struct Node_t *next;
} Node;

typedef Node *StackType;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    printf("Input data: "); scanf("%d", &e.num);
    return e;
}

void print_data(ElementType e) {
    printf("%3d", e.num);
}

// Stack list functions------------------------------------------------------------
int is_empty(StackType top){
    return (top == NULL);
}

Node *push(ElementType e, StackType *top){
    /* return the new top of the stack 
     * return NULL if failed
     */
    Node *new = (Node *)malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new->element = e;
    new->next = (*top);
    (*top) = new;
    return new;
}

ElementType *pop(StackType *top){
    /* return a pointer to the ElementType removed from the stack 
     * return NULL if failed
     */
    if (is_empty(*top)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    
    ElementType *e = (ElementType *)malloc(sizeof(ElementType));
    if (e == NULL) {
        printf("Memory allocation for popped element failed!\n");
        return NULL;
    }

    Node *temp = *top;
    *e = temp->element;
    *top = temp->next;
    free(temp);
    return e;
}

ElementType *peek(StackType top){
    if (is_empty(top)){
        printf("Stack is empty!\n");
        return NULL;
    }
    else
        return &(top->element);
}

StackType top;
/*
 * Remember to check for null pointer returned by peek() and pop()
 */

int main(){
    int a[6] = {1,2,3,5,7,9};
    
    printf(is_empty(top)? "empty\n":"Not empty\n");

    for (int i=0; i<6; i++) {
        ElementType e;
        e.num = a[i];
        push(e, &top);
        print_data(e);
    }
    printf("\n");
    printf("Pop all elements in stack!\n");
    while (!is_empty(top)) {
        printf("top: ");
        print_data(*peek(top));
        print_data(*pop(&top));
    }
    printf("\n");

    printf("peak: %d\n", (*peek(top)).num);

    return 0;
}