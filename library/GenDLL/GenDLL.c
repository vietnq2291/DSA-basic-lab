#include<stdio.h>
#include<stdlib.h>
#include"GenDLL.h"

DoubleList root, tail, cur;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    printf("data: "); scanf("%d", &e.num);
    return e;
}

void print_data(ElementType e) {
    printf("%3d", e.num);
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
    new->prev = NULL;
    return new;
}

void make_null_list(DoubleList *root, DoubleList *tail, DoubleList *cur) {
    (*root) = NULL;
    (*cur) = NULL;
    (*tail) = NULL;
}

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
        if (cur->element.num == e.num){
            // check if deleting root node
            if (cur == (*root)) (*root) = cur->next;
            else cur->prev->next = cur->next;
            // check if deleting tail node
            if (cur->next != NULL) cur->next->prev = cur->prev;
            else (*tail) = cur->prev;

            free(cur);
            return;
        }
        prev = cur;
    }
}

// Node *split(DoubleList *root, int n1, int n2) {
//     Node *cur = *root,
//          *prev_slist = NULL,
//          *sublist = NULL;
// 
//     // list of 0 elements
//     if (n2 <= 0) return NULL;
// 
//     // invalid index
//     if (n1 < 0) return NULL;
// 
//     // find head of sublist
//     for (int i = 0; i < n1; i++) {
//         if (cur->next == NULL){
//             return sublist;
//         }
//         prev_slist = cur;
//         cur = cur->next;
//     }
//     sublist = cur;
// 
//     // traverse the sublist
//     for (int i = 0; i < n2-1; i++) {
//         if (cur->next == NULL) {
//             break;
//         }
//         cur = cur->next;
//     }
// 
//     if (prev_slist != NULL) prev_slist->next = cur->next;
//     else (*root) = cur->next;
//     cur->next = NULL;
// 
//     return sublist;
// }

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

void traverse_list(DoubleList root) {
    Node *p;
    for (p = root; p != NULL; p = p->next){
        print_data(p->element);
    }
    printf("\n");
}


