#include<stdio.h>

#define MAXLEN 10
typedef int ElementType;
typedef struct {
    ElementType elements[MAXLEN];
    int front, rear;
} Queue;

void make_null_queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int is_empty_queue(Queue q){
    return q.front == -1;
}

int is_full_queue(Queue q){
    return (q.rear - q.front + 1) == MAXLEN;
}

void enqueue(ElementType x, Queue *q){
    if (!is_full_queue(*q)){
        if (is_empty_queue(*q))
            q->front = 0;
        q->rear = q->rear + 1;
        q->elements[q->rear] = x;
    }
    else
        printf("Queue is full!\n");
}

ElementType dequeue(Queue *q){
    ElementType e;
    if (!is_empty_queue(*q)){
        e = q->elements[q->front];
        q->front = q->front + 1;
        if (q->front > q->rear)
            make_null_queue(q);
        return e;
    }
    printf("Queue is empty!\n");
    return -1;
}


int main(){
    int num;
    Queue q;
    make_null_queue(&q);

    printf("Enter 11 numbers: ");
    for (int i = 0; i < 10; i++){
        scanf("%d", &num);
        enqueue(num, &q);
    }

    printf("queue elements: ");
    while(!is_empty_queue(q)){
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}
