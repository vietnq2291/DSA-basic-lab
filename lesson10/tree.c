#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

Node *root;

// ElementType functions-------------------------------------------------------
ElementType read_data(FILE *fptr, Node *root) {
    ElementType lane;

    // lane name & length
    fscanf(fptr, "%s", lane.name);
    fscanf(fptr, "%f", &lane.length);

    return lane;
}

void print_data(ElementType e) {
    printf("%s %.2f ", e.name, e.length);
}


// Tree functions-------------------------------------------------------------
Node *make_new_node(ElementType e) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }

    strcpy(new->element.name, e.name);
    new->element.length = e.length;

    new->left_most_child = NULL;
    new->right_sibling = NULL;
    return new;
}

Node *find(Node *r, ElementType e) {
    if (r == NULL) return NULL;

    // found the node
    if (strcmp(strtok(r->element.name, " "), strtok(e.name, " ")) == 0) 
        return r;

    // DFS from node r
    Node *p = r->left_most_child;
    while (p != NULL) {
        Node *q = find(p, e); // continue search its child
        if (q != NULL) return q; // found the node q
        p = p->right_sibling; // continue search its sibling
    }
    return NULL;
}

void add_child(ElementType parent, ElementType child, Node *root) {
    Node *r = find(root, parent);
    if (r == NULL) return;
    r->left_most_child = add_last(r->left_most_child, child);
}

Node *add_last(Node *p, ElementType e) {
    // add new node as right most sibling of p
    if (p == NULL) return make_new_node(e);
    p->right_sibling = add_last(p->right_sibling, e);
    return p;
}

void print_tree(Node *r) {
    if (r == NULL) return;
    // print parent
    if (strcmp(r->element.name, "root") != 0) {
        print_data(r->element);
        printf(": ");
    } else {
        printf("root:  ");
    }
    

    // print children
    Node *p = r->left_most_child;
    while (p != NULL) {
        print_data(p->element);
        p = p->right_sibling;
    }
    printf("\n");

    // continue print all levels of tree
    p = r->left_most_child;
    while (p != NULL) {
        print_tree(p);
        p = p->right_sibling;
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
