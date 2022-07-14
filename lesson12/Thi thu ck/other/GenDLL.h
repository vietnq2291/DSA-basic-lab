#include<stdlib.h>
// define element type & Node -------------------------------------------------
typedef struct{
    char name[20];
    int memory;
    float screen;
    int price;    
} ElementType;

typedef struct Node_t {
    ElementType element;
    struct Node_t *next;
    struct Node_t *prev;
} Node;

typedef Node *DoubleList;

// ElementType functions-------------------------------------------------------
extern ElementType read_data();
extern void print_data(ElementType e, FILE *fptr);

//// Double linked list functions------------------------------------------------
extern Node *make_new_node(ElementType e);
extern void make_null_list(DoubleList *root, DoubleList *tail, DoubleList *cur);
extern int is_empty(DoubleList root);

extern void insert_at_head(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur);
extern void insert_at_tail(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur);
extern void insert_after_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur);
extern void insert_before_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur);
extern Node *insert_at_position(ElementType e, int n, DoubleList *root, DoubleList *tail, DoubleList *cur);

extern Node *delete_at_position(int n, DoubleList *root, DoubleList *tail);
extern void delete_element(ElementType e, DoubleList *root, DoubleList *tail);

extern Node *list_reverse(DoubleList *root, DoubleList *tail);

extern void traverse_list(DoubleList root);
extern void free_list(DoubleList *root, DoubleList *tail, DoubleList *cur);

extern Node *search(char name[], DoubleList *root, DoubleList *tail);