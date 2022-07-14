typedef char ElementType;
typedef struct Node_t {
    ElementType element;
    struct Node_t *next;
} Node;
typedef Node *StackType;

extern int is_empty(StackType top);
extern void push(ElementType e, StackType *top);
extern ElementType pop(StackType *top);
extern ElementType peek(StackType top);
