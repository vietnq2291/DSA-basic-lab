#include <stdio.h>

#define SIZE 5
typedef int ElementType;
typedef struct {
    ElementType elements[SIZE];
    int front, rear;
} Queue;

void make_null_queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}
// Check if the queue is full
int isFull(Queue q) {
  if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty(Queue q) {
  if (q.front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(ElementType e, Queue *q) {
  if (isFull(*q))
    printf("\n Queue is full!! \n");
  else {
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % SIZE;
    q->elements[q->rear] = e;
    printf("\n Inserted -> %d", e);
  }
}

// Removing an element
int deQueue(Queue *q) {
  ElementType e;
  if (isEmpty(*q)) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    e = q->elements[q->front];
    if (q->front == q->rear) {
      q->front = -1;
      q->rear = -1;
    }
    else {
      q->front = (q->front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", e);
    return (e);
  }
}

void display(Queue q) {
  int i;
  if (isEmpty(q))
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", q.front);
    printf("\n Items -> ");
    for (i = q.front; i != q.rear; i = (i + 1) % SIZE) {
      printf("%d ", q.elements[i]);
    }
    printf("%d ", q.elements[i]);
    printf("\n Rear -> %d \n", q.rear);
  }
}

int main() {
  Queue q;
  ElementType x;
  make_null_queue(&q);

  for (int i = 0; i < 6; i++){
      scanf("%d", &x);
      if (i < SIZE)
          enQueue(x, &q);
      else{
          deQueue(&q);
          q.rear = (q.rear) % SIZE;
          enQueue(x, &q);
      }
  }
  display(q);

  return 0;
}
