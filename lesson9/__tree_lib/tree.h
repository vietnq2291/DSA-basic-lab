// define element type & Node -------------------------------------------------
typedef struct{
    char name[256];
} ElementType;

typedef struct Node_t {
    ElementType element;
    struct Node_t *left_most_child;
    struct Node_t *right_sibling;
} Node;

// ElementType functions-------------------------------------------------------
extern ElementType read_data();
extern void print_data(ElementType e);

// Queue functions-------------------------------------------------------------
extern Node *make_new_node(ElementType e);
extern Node *find(Node *r, ElementType e);
extern Node *add_last(Node *p, ElementType e);
extern void add_child(ElementType parent, ElementType child, Node *root);
extern void print_tree(Node *r);

extern void process_find(Node *root);
extern void process_find_children(Node *root);
extern void process_height(Node *root);
extern void process_print(Node *root);
extern void process_add_child(Node *root);
extern void process_add_sibling(Node *root);
extern int count(Node* r);
extern void processCount();
















// extern void make_null_queue(Queue *q);
// extern int is_empty(Queue q);

// extern void enqueue(ElementType e, Queue *q);
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

