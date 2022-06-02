#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node_t {
    char name[256];
    struct Node_t* left_most_child;
    struct Node_t* right_sibling;
} Node;
Node *root;


Node *make_node(char *name) {
    Node *p = (Node *) malloc(sizeof(Node));
    strcpy(p->name, name);
    p->left_most_child = NULL;
    p->right_sibling = NULL;
    return p;
}

Node *find(Node *r, char *name) {
    if (r == NULL) return NULL;
    if (strcmp(r->name, name) == 0) return r;

    Node *p = root->left_most_child;
    while (p != NULL) {
        Node *q = find(p, name);
        if (q != NULL) return q;
        p = p->right_sibling;
    }
    return NULL;
}

Node *add_last(Node *p, char *name) {
    if (p == NULL) return make_node(name);
    p->right_sibling = add_last(p->right_sibling, name);
    return p;
}

void add_child(char *name, char *child) {
    Node *r = find(root, name);
    if (r == NULL) return;
    r->left_most_child = add_last(r->left_most_child, child);
}

void print_tree(Node *r) {
    if (r == NULL) return;
    printf("%s: ", r->name);

    Node *p = r->left_most_child;
    while (p != NULL) {
        printf("%s ", p->name);
        p = p->right_sibling;
    }
    printf("\n");

    p = r->left_most_child;
    while (p != NULL) {
        print_tree(p);
        p = p->right_sibling;
    }
}

int main() {
    root = make_node("cụ tổ");
    add_child("to tien", "con 1");
    print_tree(root);

    return 0;
}
