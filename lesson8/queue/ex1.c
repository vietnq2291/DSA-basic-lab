#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 5
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
    return q.front == -1 && q.rear == -1;
}

int is_full_queue(Queue q){
    return abs(q.rear - q.front + 1) % MAXLEN == 0;
}

void enqueue(ElementType x, Queue *q){
    if (!is_full_queue(*q)){
        if (is_empty_queue(*q)){
            q->front = 0;
            q->rear = 0;
            q->elements[q->rear] = x;
            return;
        }
        q->rear = (q->rear + 1) % MAXLEN;
        q->elements[q->rear] = x;
    } else {
        printf("full!\n");
    }
}

ElementType dequeue(Queue *q){
    ElementType e;
    if (!is_empty_queue(*q)){
        if (q->front != q->rear){
            e = q->elements[q->front];
            q->front = (q->front + 1) % MAXLEN;
        }
        return e;
    }
    printf("Queue is empty!\n");
    return -1;
}


int main(){
    int num, j=0;
    Queue q;
    ElementType e;
    make_null_queue(&q);

    printf("Enter 11 numbers: ");
    for (int i = 0; i < 3; i++, j++){
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
