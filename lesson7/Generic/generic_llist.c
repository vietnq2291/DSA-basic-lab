#include<stdio.h>
#include<stdlib.h>

// define element type & node -------------------------------------------------
typedef struct{
    // define element type here...
    int num;
}elementtype;

typedef struct node_t {
    elementtype element;
    struct node_t *next;
} node;
node *root, *cur, *prev;


// functions for elementtype---------------------------------------------------
elementtype read_data(){
    elementtype res;

    printf("data: "); scanf("%d", &res.num);

    return res;
}

void print_data(elementtype e){
    printf("%15d\n", e.num);
}


// functions with nodes--------------------------------------------------------
node *make_new_node(elementtype e){
    node *new = (node *) malloc(sizeof(node));
    if (new == NULL){
        printf("Failed allocating memory for new node!\n");
        return NULL;
    }
    new->element = e;
    new->next = NULL;
    return new;
}

void insert_after_current(elementtype e){
    node *new = make_new_node(e);

    if (root == NULL){
        root = new;
        cur = root;
        prev = NULL;
    } else if (cur == NULL){
        printf("Cannot insert new node - Current pointer points to NULL!\n");
        return;
    } else {
        new->next = cur->next;
        cur->next = new;
        prev = cur;
        cur = cur->next;
    }
}

void insert_before_current(elementtype e){
    node *new = make_new_node(e);

    if (root == NULL){
        root = new;
        cur = root;
        prev = NULL;
    } else if (cur == NULL){
        printf("Cannot insert new node - Current pointer points to NULL!\n");
        return;
    } else {
        new->next = cur;

        if (cur == root) root = new;
        else prev->next = new;

        cur = new;
    }
}

void delete_element(elementtype e){
    node *cur, *prev;
    for (cur = root; cur != NULL; cur = cur->next){
        if (cur->element.num == e.num){
            if (cur == root) root = cur->next;
            else prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
    }
}

node *insert_at_position(elementtype e, int n){
    int i;

    if (n <= 0) return NULL;
    cur = root;
    for (i = 1; i < n; i++){
        if (cur == NULL){
            return NULL;
        }
        prev = cur;
        cur = cur->next;
    }

    insert_before_current(e);
    return cur;
}

node *delete_at_position(int n){
    int i = 1;
    node *cur, *prev;
    for (cur = root; cur != NULL; cur = cur->next, i++){
        if (i == n){
            if (cur == root) root = cur->next;
            else prev->next = cur->next;
            free(cur);
            break;
        }
        prev = cur;
    }
    return root;
}

node *list_reverse(node *root){
    node *cur, *prev;
    cur = prev = NULL;

    while (root != NULL){
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

void traverse_list(){
    node *p;
    for (p = root; p != NULL; p = p->next){
        print_data(p->element);
    }
}


int main(){
//    elementtype e1 = read_data();
//    node *n1 = make_new_node(e1);
//    elementtype e2 = read_data();
//    node *n2 = make_new_node(e2);
//    elementtype e3 = read_data();
//    node *n3 = make_new_node(e3);
//    elementtype e4 = read_data();
//    node *n4 = make_new_node(e4);
//    elementtype e5 = read_data();
//    node *n5 = make_new_node(e5);

    elementtype e1 = read_data();
    insert_after_current(e1);
    elementtype e2 = read_data();
    insert_after_current(e2);
    elementtype e3 = read_data();
    insert_after_current(e3);
    elementtype e4 = read_data();
    insert_after_current(e4);
    elementtype e5 = read_data();
    insert_before_current(e5);
    elementtype e6 = read_data();
    traverse_list();

    printf("root: %d - %p\n", root->element.num, root);
    printf("\n");

    root = delete_at_position(1);

    traverse_list();
    printf("root: %d - %p\n", root->element.num, root);
    return 0;
}
