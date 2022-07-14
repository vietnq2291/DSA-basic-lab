#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

Node *root;

// ElementType functions-------------------------------------------------------
ElementType read_data(FILE *fptr) {
    ElementType e;

    fscanf(fptr, "%s%f", e.name, &e.cost);
    return e;
}

void print_data(ElementType e) {
    printf("%s\t\t%.2f\n", e.name, e.cost);
}

// Queue functions-------------------------------------------------------------

Node *make_new_node(ElementType e) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }

    strcpy(new->element.name, e.name);
    new->element.cost = e.cost;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

Node *find(Node *r, ElementType e) {
    if (r == NULL) return NULL;

    // found the node
    if (strcmp(r->element.name, e.name) == 0) return r;

    if (r->element.cost < e.cost) {
        return find(r->right_child, e);
    } else {
        return find(r->left_child, e);
    }
}

Node *insert_node(Node *root, ElementType e) {
    if (root == NULL) return make_new_node(e);
    if (find(root, e) != NULL) return root;

    if (strcmp(root->element.name, e.name) > 0) {
        root->right_child = insert_node(root->right_child, e);
    } else if(strcmp(root->element.name, e.name) < 0) {
        root->left_child = insert_node(root->left_child, e);
    }
    return root;
}

void print_tree(Node *r) {
    if (r == NULL) return;

    if (r->left_child != NULL) {
        print_tree(r->left_child);
    }
    print_data(r->element);
    if (r->right_child != NULL) {
        print_tree(r->right_child);
    }
}

// // ????????????????
// int height(Node* p){
//     if(p == NULL) return 0;

//     int maxH = 0;
//     Node* q = p->left_most_child;
//     while(q != NULL){
//         int h = height(q);
//         maxH = maxH < h ? h : maxH;
//         q = q->right_sibling;
//     }
//     return maxH + 1;
// }

// void process_find(Node *root) {
//     char name[256];
//     ElementType e = read_data();
    
//     Node *p = find(root, e);
//     if (p == NULL) printf("Not found %s\n", e.name);
//     else printf("Found %s\n", e.name);
// }

// void process_find_children(Node *root){
//     ElementType e = read_data();
//     Node* q = find(root, e);
    
//     if(q == NULL) printf("Not Found %s\n", e.name);
//     else{
//         printf("Found %s with children: ", e.name);
//         Node *p = q->left_most_child;
//         while (p != NULL) {
//             print_data(p->element);
//             p = p->right_sibling;
//         }
//         printf("\n");
//     }
// }

// void process_height(Node *root) {
//     ElementType e = read_data();
//     Node* p = find(root, e);

//     if(p == NULL) printf("Not Found %s\n", e.name);
//     else printf("Found %s having height = %d\n", e.name, height(p));
// }

// void process_print(Node *root) {
//     ElementType e = read_data();
    
//     Node *p = find(root, e);
//     if (p == NULL) printf("Not found %s\n", e.name);
//     else print_tree(p);
// }

// void process_add_child(Node *root) {
//     ElementType parent = read_data();
//     ElementType child = read_data();
//     add_child(parent, child, root);
// }

// void process_add_sibling(Node *root) {
//     printf("Sibling of: ");
//     ElementType e = read_data();
//     Node *p = find(root, e);

//     if (p == NULL) printf("Not Found %s\n", e.name);
//     else {
//         printf("New node: ");
//         ElementType new = read_data();
//         add_last(p, new);
//     }

// }

// int count(Node* r){
//     if(r == NULL) return 0;
//     int cnt = 1;
//     Node* q = r->left_most_child;
//     while(q != NULL){
//         cnt += count(q);
//         q = q->right_sibling;
//     }
//     return cnt;
// }

// void processCount(){
//     printf("Number of members is %d\n", count(root));
// }



















// void make_null_queue(Queue *q) {
//     Position Header;

//     Header = (Node *) malloc(sizeof(Node));
//     Header->next = NULL;
//     q->front = Header;
//     q->rear = Header;
// }

// int is_empty(Queue q) {
//     return (q.front == NULL);
// }

// void enqueue(ElementType e, Queue *q) {
//     Node *new = make_new_node(e);

//     if (new == NULL){
//         printf("Make new node failed!\n");
//         return;
//     }

//     // insert to empty list
//     if ((*root) == NULL) {
//         (*root) = new;
//         (*cur) = new;
//         (*prev) = NULL;
//         return;
//     }

//     new->next = (*root);
//     (*root) = new;
//     (*cur) = new;
//     (*prev) = NULL;
// }

// void insert_after_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
//     Node *new = make_new_node(e);
// 
//     if (new == NULL){
//         printf("Make new node failed!\n");
//         return;
//     }
// 
//     // insert into empty list
//     if ((*root) == NULL){
//         (*root) = new;
//         (*cur) = new;
//         (*prev) = NULL;
//         return;
//     }
// 
//     // current pointer points to NULL
//     if ((*cur) == NULL){
//         printf("Cannot insert new Node - Current pointer points to NULL!\n");
//         return;
//     }
// 
//     new->next = (*cur)->next;
//     (*cur)->next = new;
//     (*prev) = (*cur);
//     (*cur) = new;
// }
// 
// void insert_before_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
//     Node *new = make_new_node(e);
// 
//     if (new == NULL){
//         printf("Make new node failed!\n");
//         return;
//     }
// 
//     // insert into empty list
//     if ((*root) == NULL){
//         (*root) = new;
//         (*cur) = new;
//         (*prev) = NULL;
//         return;
//     }
// 
//     // current pointer points to NULL
//     if ((*cur) == NULL){
//         printf("Cannot insert new Node - Current pointer points to NULL!\n");
//         return;
//     }
// 
//     new->next = (*cur);
//     if ((*cur) == (*root)) (*root) = new;
//     else (*prev)->next = new;
//     (*cur) = new;
// }
// 
// Node *insert_at_position(ElementType e, int n, SingleList *root, SingleList *cur, SingleList *prev) {
//     // out of index n
//     if (n < 0) return NULL;
// 
//     // insert at head
//     if (n == 0) {
//         insert_at_head(e, root, cur, prev);
//         return (*root);
//     }
// 
//     // traverse the list to get the nth node
//     (*cur) = (*root);
//     for (int i = 0; i < n-1; i++){
//         if ((*cur)->next == NULL){
//             return NULL;
//         }
//         (*prev) = (*cur);
//         (*cur) = (*cur)->next;
//     }
// 
//     insert_after_current(e, root, cur, prev);
//     return (*cur);
// }
// 
// Node *delete_at_position(int n, SingleList *root) {
//     Node *cur =  *root,
//          *prev = NULL;
// 
//     // invalid index
//     if (n < 0) return (*root);
// 
//     for (int i = 0; i < n; i++) {
//         if (cur->next == NULL){
//             return (*root);
//         }
//         prev = cur;
//         cur = cur->next;
//     }
// 
//     if (cur == (*root)) (*root) = cur->next;
//     else prev->next = cur->next;
//     free(cur);
// 
//     return (*root);
// }
// 
// void delete_element(ElementType e, SingleList *root){
//     Node *cur, *prev;
//     for (cur = (*root); cur != NULL; cur = cur->next){
//         if (cur->element.num == e.num){
//             if (cur == (*root)) (*root) = (*root)->next;
//             else prev->next = cur->next;
//             free(cur);
//             return;
//         }
//         prev = cur;
//     }
// }
// 
// Node *split(SingleList *root, int n1, int n2) {
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
// 
// Node *list_reverse(SingleList *root) {
//     Node *cur, *prev;
//     cur = prev = NULL;
// 
//     while ((*root) != NULL) {
//         cur = (*root);
//         (*root) = (*root)->next;
//         cur->next = prev;
//         prev = cur;
//     }
//     return prev;
// }
// 
// void traverse_list(SingleList root) {
//     Node *p;
//     for (p = root; p != NULL; p = p->next){
//         print_data(p->element);
//     }
//     printf("\n");
// }
// 
// 
