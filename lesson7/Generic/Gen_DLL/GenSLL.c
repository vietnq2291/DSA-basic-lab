#include<stdio.h>
#include<stdlib.h>
#include"GenSLL.h"

SingleList root, cur, prev;

// ElementType functions-------------------------------------------------------
ElementType read_data(){
    ElementType e;
    printf("data: "); scanf("%d", &e.num);
    return e;
}

void print_data(ElementType e){
    printf("%15d\n", e.num);
}


// Single linked list functions------------------------------------------------
void make_null_list(SingleList *root, SingleList *cur, SingleList *prev) {
    (*root) = NULL;
    (*cur) = NULL;
    (*prev) = NULL;
}

int is_empty(SingleList root){
    return (root == NULL);
}

Node *make_new_node(ElementType e){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;
    return new;
}

void insert_at_head(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    Node *new = make_new_node(e);

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

void traverse_list(SingleList root){
    Node *p;
    for (p = root; p != NULL; p = p->next){
        print_data(p->element);
    }
}
void insert_after_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev){
    Node *new = make_new_node(e);

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

void insert_before_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev){
    Node *new = make_new_node(e);

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

Node *insert_at_position(ElementType e, int n, SingleList *root, SingleList *cur, SingleList *prev){
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
        if ((*cur) == NULL || (*cur)->next == NULL){
            return NULL;
        }
        (*prev) = (*cur);
        (*cur) = (*cur)->next;
    }

    insert_after_current(e, root, cur, prev);
    return (*cur);
}

Node *delete_at_position(int n, SingleList *root){
    Node *cur =  *root,
         *prev = NULL;

    for (int i = 0; i < n; i++) {
        if (cur == NULL || cur->next == NULL){
            return (*root);
        }
        prev = cur;
        cur = cur->next;
    }

    if (cur == (*root)) (*root) = cur->next;
    else prev->next = cur->next;
    free(cur);

    return (*root);
}

// void delete_element(ElementType e){
//     Node *cur, *prev;
//     for (cur = root; cur != NULL; cur = cur->next){
//         if (cur->element.num == e.num){
//             if (cur == root) root = cur->next;
//             else prev->next = cur->next;
//             free(cur);
//             return;
//         }
//         prev = cur;
//     }
// }
// 
// 
// Node *list_reverse(Node *root){
//     Node *cur, *prev;
//     cur = prev = NULL;
// 
//     while (root != NULL){
//         cur = root;
//         root = root->next;
//         cur->next = prev;
//         prev = cur;
//     }
//     return prev;
// }
// 
