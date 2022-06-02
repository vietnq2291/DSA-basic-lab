#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node_t {
    ElementType element;
    struct Node_t* next;
} Node;
typedef Node* Position;
typedef struct{
    Position front, rear;
} Queue;

void make_null_queue(Queue *q){
    Position header;

    header = (Node*) malloc(sizeof(Node));
    header->next = NULL;
    q->front = header;
    q->rear = header;
}

int is_empty_queue(Queue q){
    return (q.front == NULL);
}

void enqueue(ElementType e, Queue *q){
    q->rear->next = (Node *) malloc(sizeof(Node));
    q->rear = q->rear->next;
    q->rear->next = NULL;
    q->rear->element = e;
}

ElementType dequeue(Queue q){
    ElementType e;

    if (!is_empty_queue(*q)){
        e = q->element->
    }
}

int main(){

    return 0;
}
