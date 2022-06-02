#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"GenSLL.h"

SingleList root, cur, prev;

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


// Single linked list functions------------------------------------------------
Node *make_new_node(ElementType e) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;
    return new;
}

void make_null_list(SingleList *root, SingleList *cur, SingleList *prev) {
    (*root) = NULL;
    (*cur) = NULL;
    (*prev) = NULL;
}

int is_empty(SingleList root) {
    return (root == NULL);
}

void insert_at_head(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert to empty list
    if ((*root) == NULL) {
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return;
    }

    new->next = (*root);
    (*root) = new;
    (*cur) = new;
    (*prev) = NULL;
}

void insert_after_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return;
    }

    new->next = (*cur)->next;
    (*cur)->next = new;
    (*prev) = (*cur);
    (*cur) = new;
}

void insert_before_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return;
    }

    new->next = (*cur);
    if ((*cur) == (*root)) (*root) = new;
    else (*prev)->next = new;
    (*cur) = new;
}

Node *insert_at_position(ElementType e, int n, SingleList *root, SingleList *cur, SingleList *prev) {
    // out of index n
    if (n < 0) return NULL;

    // insert at head
    if (n == 0) {
        insert_at_head(e, root, cur, prev);
        return (*root);
    }

    // traverse the list to get the nth node
    (*cur) = (*root);
    for (int i = 0; i < n-1; i++){
        if ((*cur)->next == NULL){
            return NULL;
        }
        (*prev) = (*cur);
        (*cur) = (*cur)->next;
    }

    insert_after_current(e, root, cur, prev);
    return (*cur);
}

Node *delete_at_position(int n, SingleList *root) {
    Node *cur =  *root,
         *prev = NULL;

    // invalid index
    if (n < 0) {
        printf("Deletion failed\n");
        return (*root);
    }

    for (int i = 0; i < n; i++) {
        if (cur->next == NULL){
            printf("Deletion failed\n");
            return (*root);
        }
        prev = cur;
        cur = cur->next;
    }

    if (cur == (*root)) (*root) = cur->next;
    else prev->next = cur->next;
    free(cur);
    printf("Deleted successfully!\n");

    return (*root);
}

void delete_element(ElementType e, SingleList *root){
    Node *cur, *prev;
    for (cur = (*root); cur != NULL; cur = cur->next){
        if (cur->element.name == e.name){
            if (cur == (*root)) (*root) = (*root)->next;
            else prev->next = cur->next;
            free(cur);
            printf("Deleted successfully!\n");
            return;
        }
        prev = cur;
    }
    printf("Deletion failed\n");
}

Node *split(SingleList *root, int n1, int n2) {
    Node *cur = *root,
         *prev_slist = NULL,
         *sublist = NULL;

    // list of 0 elements
    if (n2 <= 0) return NULL;

    // invalid index
    if (n1 < 0) return NULL;

    // find head of sublist
    for (int i = 0; i < n1; i++) {
        if (cur->next == NULL){
            return sublist;
        }
        prev_slist = cur;
        cur = cur->next;
    }
    sublist = cur;

    // traverse the sublist
    for (int i = 0; i < n2-1; i++) {
        if (cur->next == NULL) {
            break;
        }
        cur = cur->next;
    }

    if (prev_slist != NULL) prev_slist->next = cur->next;
    else (*root) = cur->next;
    cur->next = NULL;

    return sublist;
}

Node *list_reverse(SingleList *root) {
    Node *cur, *prev;
    cur = prev = NULL;

    while ((*root) != NULL) {
        cur = (*root);
        (*root) = (*root)->next;
        cur->next = prev;
        prev = cur;
    }
    printf("Reversed successfully!\n");
    return prev;
}

void traverse_list(SingleList root) {
    Node *p;
    int i=0;

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    for (p = root; p != NULL; p = p->next, i++){
        fprintf(stdout, " %-3d ", i);
        print_data(p->element, stdout);
    }
    printf("\n");
}

extern Node *search(char name[], SingleList *root, SingleList *cur, SingleList *prev) {
    Node *temp_cur, *temp_prev;
    int i=0;

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    for (temp_cur = (*root); temp_cur != NULL; i++){
        if (strcmp(name, temp_cur->element.name) == 0) {
            printf("name: %s\n", name);
            printf("phone name: %s\n", temp_cur->element.name);
            printf(" %-3d ", i);
            print_data(temp_cur->element, stdout);
            printf("\n");

            (*prev) = temp_prev;
            (*cur) = temp_cur;
            return (*cur);
        }
        temp_prev = temp_cur;
        temp_cur = temp_cur->next;
    }
    return NULL;
}


