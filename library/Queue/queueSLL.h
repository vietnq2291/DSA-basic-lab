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
} Queue;

// ElementType functions-------------------------------------------------------
extern ElementType read_data();
extern void print_data(ElementType e);

// Queue functions-------------------------------------------------------------
extern Node *make_new_node(ElementType e);
extern void make_null_queue(Queue *q);
extern int is_empty(Queue q);

extern void enqueue(ElementType e, Queue *q);
// extern void insert_after_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev);
// extern void insert_before_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev);
// extern Node *insert_at_position(ElementType e, int n, SingleList *root, SingleList *cur, SingleList *prev);
// 
// extern Node *delete_at_position(int n, SingleList *root);
// extern void delete_element(ElementType e, SingleList *root);
// 
// extern Node *split(SingleList *root, int n1, int n2);
// extern Node *list_reverse(SingleList *root);
// 
// extern void traverse_list(SingleList root);

