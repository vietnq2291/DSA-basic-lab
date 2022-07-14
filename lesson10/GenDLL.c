#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"GenDLL.h"

DoubleList root, tail, cur;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    
    printf("Adding new phone:\n");
    printf("- Name: "); scanf("%[^\n]", e.name);
    printf("- Memory: "); scanf("%d", &e.memory);
    printf("- Screen: "); scanf("%f", &e.screen);
    printf("- Price: "); scanf("%d", &e.price);
    
    return e;
}

void print_data(ElementType e, FILE *fptr) {
    fprintf(fptr, "%-25s %6d %13.2f %16d\n", e.name, e.memory, e.screen, e.price);
}


// Double linked list functions------------------------------------------------
Node *make_new_node(ElementType e) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

// void make_null_list(DoubleList *root, DoubleList *tail, DoubleList *cur) {
//     (*root) = NULL;
//     (*cur) = NULL;
//     (*tail) = NULL;
// }

int is_empty(DoubleList root) {
    return (root == NULL);
}

void insert_at_head(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert to empty list
    if ((*root) == NULL) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return;
    }

    new->next = (*root);
    (*root)->prev = new;
    (*root) = new;
    (*cur) = (*root);
}

void insert_at_tail(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert to empty list
    if ((*tail) == NULL) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return;
    }

    (*tail)->next = new;
    new->prev = (*tail);
    (*tail) = new;
    (*cur) = (*tail);
}

void insert_after_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return;
    }

    new->next = (*cur)->next;

    // cur is NOT the last node of the list (tail)
    if ((*cur)->next != NULL) (*cur)->next->prev = new;
    else (*tail) = new;

    (*cur)->next = new;
    new->prev = (*cur);
    (*cur) = new;
}

void insert_before_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return;
    }

    new->next = (*cur);
    // cur is NOT the first node of the list (root)
    if ((*cur) != (*root)) (*cur)->prev->next = new;
    else {
        (*root) = new;
        new->prev = (*cur)->prev;
    }
    (*cur)->prev = new;
    (*cur) = new;
}

Node *insert_at_position(ElementType e, int n, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    // out of index n
    if (n < 0) return NULL;

    // insert at head
    if (n == 0 || is_empty(*root)) {
        insert_at_head(e, root, tail, cur);
        return (*root);
    }

    // traverse the list to get the nth node
    (*cur) = (*root);
    for (int i = 0; i < n-1; i++){
        if ((*cur)->next == NULL){
            return NULL;
        }
        (*cur)->prev = (*cur);
        (*cur) = (*cur)->next;
    }

    insert_after_current(e, root, tail, cur);
    return (*cur);
}

Node *delete_at_position(int n, DoubleList *root, DoubleList *tail) {
    Node *cur =  *root,
         *prev = NULL;

    // invalid index
    if (n < 0) return (*root);

    for (int i = 0; i < n; i++) {
        if (cur->next == NULL){
            return (*root);
        }
        prev = cur;
        cur = cur->next;
    }

    // check if deleting root node
    if (cur == (*root)) (*root) = cur->next;
    else cur->prev->next = cur->next;
    // check if deleting tail node
    if (cur->next != NULL) cur->next->prev = cur->prev;
    else (*tail) = cur->prev;
    free(cur);

    return (*root);
}

void delete_element(ElementType e, DoubleList *root, DoubleList *tail){
    Node *cur, *prev;
    for (cur = (*root); cur != NULL; cur = cur->next){
        if (strcmp(cur->element.name, e.name) == 0){
            // check if deleting root node
            if (cur == (*root)) (*root) = cur->next;
            else cur->prev->next = cur->next;
            // check if deleting tail node
            if (cur->next != NULL) cur->next->prev = cur->prev;
            else (*tail) = cur->prev;

            free(cur);
            printf("Deleted successfully!\n");
            return;
        }
        prev = cur;
    }
    printf("Deletion failed\n");
}

Node *list_reverse(DoubleList *root, DoubleList *tail) {
    Node *temp, *cur = (*root);

    // empty list
    if ((*root) == NULL) return NULL;

    // reverse root and tail node
    temp = (*root);
    (*root) = (*tail);
    (*tail) = temp;

    while ((*root)->next == NULL) {
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->prev;
    }
    return *root;
}

Node *search(char name[], DoubleList *root, DoubleList *tail) {
    Node *temp_cur, *temp_prev;
    int i=0;

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    for (temp_cur = (*root); temp_cur != NULL; i++){
        if (strcmp(name, temp_cur->element.name) == 0) {
            printf(" %-3d ", i);
            print_data(temp_cur->element, stdout);
            printf("\n");

            return temp_cur;
        }
        temp_prev = temp_cur;
        temp_cur = temp_cur->next;
    }
    return NULL;
}


void traverse_list(DoubleList root) {
    Node *p;
    int i=0;

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    for (p = root; p != NULL; p = p->next, i++){
        fprintf(stdout, " %-3d ", i);
        print_data(p->element, stdout);
    }
    printf("\n");
}

void free_list(DoubleList *root, DoubleList *tail, DoubleList *cur) {
    (*cur) = (*root);

    while ((*cur) != NULL) {
        (*root) = (*root)->next;
        free(*cur);
        (*cur) = (*root);
    }
}