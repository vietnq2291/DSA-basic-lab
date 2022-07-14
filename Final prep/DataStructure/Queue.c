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

typedef Node *Position;
typedef struct {
    Position front, rear;
} QueueType;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    printf("Input data: "); scanf("%d", &e.num);
    return e;
}

void print_data(ElementType e) {
    printf("%3d", e.num);
}

// Queue functions------------------------------------------------------------
void make_null_queue(QueueType *q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(QueueType q) {
    return q.front == NULL;
}

Position enqueue(ElementType e, QueueType *q) {
    /* return pointer to new node if success, NULL if fail */
    Position new = (Position) malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;

    if (is_empty(*q)) {
        printf("insert at front\n");
        q->front = q->rear = new;
    } else {
        q->rear->next = new;
        q->rear = new;
    }
    return new;
}

ElementType *dequeue(QueueType *q) {
    /* return pointer to the popped ElementType if success, NULL if fail */
    if (is_empty(*q)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    ElementType *e = (ElementType *) malloc(sizeof(ElementType));
    if (e == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    Position p = q->front;
    *e = p->element;
    q->front = q->front->next;
    free(p);
    return e;
}

ElementType *get_front(QueueType q) {
    /* return pointer to the top ElementType if success, NULL if fail */
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    return &(q.front->element);
}

ElementType *get_rear(QueueType q) {
    /* return pointer to the rear ElementType if success, NULL if fail */
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    ElementType *e = (ElementType *) malloc(sizeof(ElementType));
    if (e == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    *e = q.rear->element;
    return e;
}

void traverse_list(Position root) {
    if (root == NULL) {
        printf("Empty list!\n");
        return;
    }

    for (Position p = root; p != NULL; p = p->next){
        print_data(p->element);
    }
    printf("\n");
}

// main function ------------------------------------------------------------
/*
 * Remember to check for null pointer returned by functions
 * Using Position instead of (Node *)
 * Create a new queue: use type QueueType and make_null_queue(&q)
 */

int main(){
    int choice;
    QueueType q;
    ElementType *eptr;
    make_null_queue(&q);

    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("enqueued: %d\n", enqueue(read_data(), &q)->element.num);
                break;
            case 2:
                eptr = dequeue(&q);
                if (eptr != NULL) {
                    printf("dequeued: "); print_data(*eptr); printf("\n");
                }
                break;
            case 3:
                printf("front: ");
                eptr = get_front(q);
                if (eptr != NULL) {
                    print_data(*eptr);
                    printf("\n");
                }
                break;
            case 4:
                printf("rear: ");
                eptr = get_rear(q);
                if (eptr != NULL) {
                    print_data(*eptr);
                    printf("\n");
                }
                break;
        }
        printf("Queue: ");
        traverse_list(q.front);
        printf("\n");
    }

    return 0;
}