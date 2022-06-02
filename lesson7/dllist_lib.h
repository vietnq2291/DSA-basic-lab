// define element type & node -------------------------------------------------
typedef struct{
}elementtype;

typedef struct node_t {
    elementtype element;
    struct node_t *next;
    struct node_t *prev;
} node;
typedef node *doublelist;
doublelist root, tail, cur;

// functions for elementtype---------------------------------------------------
elementtype read_data();

void print_data(elementtype e);

// functions with nodes--------------------------------------------------------
void make_null_list (doublelist *root, doublelist *tail, doublelist *cur);
int is_empty (doublelist root);
node *make_new_node(elementtype e);
void insert_at_head(elementtype e, doublelist *root, doublelist *tail, doublelist *cur);
void append(elementtype e, doublelist *root, doublelist *tail, doublelist *cur);
void insert_after_current(elementtype e, doublelist *root, doublelist *tail, doublelist *cur);
void insert_before_current(elementtype e, doublelist *root, doublelist *tail, doublelist *cur);
void traverse_list(doublelist *root);
