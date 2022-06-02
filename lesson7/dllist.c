#include<stdio.h>
#include<stdlib.h>

// define element type & node -------------------------------------------------
typedef struct{
    // define element type here...
    char name[20];
    char tel[11];
    char email[25];
}elementtype;

typedef struct node_t {
    elementtype element;
    struct node_t *next;
    struct node_t *prev;
} node;
typedef node *doublelist;
doublelist root, tail, cur;

// functions for elementtype---------------------------------------------------
elementtype read_data(){
    elementtype res;

    printf("Name: "); scanf(" %[^\n]", res.name);
    printf("Phone number: "); scanf("%s", res.tel);
    printf("Email: "); scanf("%s", res.email);

    return res;
}

void print_data(elementtype e){
    printf("%s \t %s \t %s\n", e.name, e.tel, e.email);
}


// functions with nodes--------------------------------------------------------
void make_null_list (doublelist *root, doublelist *tail, doublelist *cur){
    (*root) = NULL;
    (*tail) = NULL;
    (*cur) = NULL;
}

int is_empty (doublelist root){
    return (root == NULL);
}

node *make_new_node(elementtype e){
    node *new = (node *) malloc(sizeof(node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insert_at_head(elementtype e, doublelist *root, doublelist *tail, doublelist *cur){
    node *new = make_new_node(e);
    if (*root == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    new->next = *root;
    (*root)->prev = new;
    *root = new;
    *cur = *root;
}

void append(elementtype e, doublelist *root, doublelist *tail, doublelist *cur){
    node *new = make_new_node(e);
    if (*tail == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = *tail;
}

void insert_after_current(elementtype e, doublelist *root, doublelist *tail, doublelist *cur){
    node *new = make_new_node(e);

    if (root == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    } else if (cur == NULL){
        printf("Cannot insert new node - Current pointer points to NULL!\n");
        return;
    }

    new->next = (*cur)->next;
    new->prev = *cur;
    (*cur)->next = new;
    if (new->next != NULL)
        (new->next)->prev = new;
    *cur = new;
}

void insert_before_current(elementtype e, doublelist *root, doublelist *tail, doublelist *cur){
    node *new = make_new_node(e);

    if (root == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    } else if (cur == NULL){
        printf("Cannot insert new node - Current pointer points to NULL!\n");
        return;
    }

    new->next = *cur;
    if ((*cur)->prev != NULL)
        ((*cur)->prev)->next = new;
    else
        *root = new;
    new->prev = (*cur)->prev;
    (*cur)->prev = new;
    *cur = new;
}

void delete_list(doublelist p, doublelist *root, doublelist *cur, doublelist *tail){
    if (root == NULL)
        printf("Empty list\n");
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
//----------------------
}

void traverse_list(doublelist *root){
    node *p;
    for (p = *root; p != NULL; p = p->next){
        print_data(p->element);
    }
}


int main(){
    make_null_list(&root, &tail, &cur);

    // create elements
    elementtype e1 = read_data();
    elementtype e2 = read_data();
    elementtype e3 = read_data();
    elementtype e4 = read_data();
    elementtype e5 = read_data();

    // insert at head
    append(e1, &root, &tail, &cur);
    append(e2, &root, &tail, &cur);
    insert_after_current(e4, &root, &tail, &cur);
    insert_at_head(e3, &root, &tail, &cur);
    insert_before_current(e5, &root, &tail, &cur);
    insert_after_current(e4, &root, &tail, &cur);

    traverse_list(&root);
    return 0;
}
