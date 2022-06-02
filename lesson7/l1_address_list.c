#include<stdio.h>
#include<stdlib.h>

typedef struct address_t {
    char name[20];
    char tel[11];
    char email[25];
} address;

typedef struct list_el {
    address addr;
    struct list_el *next;
} node_addr;

// Define important pointers
node_addr *root, *cur;
node_addr *prev; // For deleting a node

// Functions for useful operations
node_addr* makeNewNode(address addr){
    node_addr* new = (node_addr *) malloc(sizeof(node_addr));

    new->addr = addr;
    new->next = NULL;

    return new;
}

address readNode(){
    address tmp;

    printf("Name: "); scanf(" %[^\n]", tmp.name);
    printf("Phone number: "); scanf("%s", tmp.tel);
    printf("Email: "); scanf("%s", tmp.email);

    return tmp;
}

void displayNode(node_addr *p){
    if (p == NULL){
        printf("pointer points to NULL!\n");
        return;
    }
    address tmp = p->addr;
    printf("%-20s\t%-15s\t%-30s\n", tmp.name, tmp.tel, tmp.email);
}

void insertAtHead(address addr){
    node_addr* new = makeNewNode(addr);
    new->next = root;
    root = new;
    cur = root;
}

void insertAfterCurrent(address addr){
    if (cur == NULL){
        printf("Current pointer points to NULL!\n");
        return;
    }

    node_addr* new = makeNewNode(addr);
    if (root == NULL){
        // if the list is empty -> new will be the only node in the list
        root = new;
        cur = root;
    } else {
        new->next = cur->next;
        cur->next = new;
        prev = cur;
        cur = cur->next;
    }
}

void insertBeforeCurrent(address addr){
    if (cur == NULL){
        printf("Current pointer points to NULL!\n");
        return;
    }

    node_addr* new = makeNewNode(addr);
    if (root == NULL){
        // if list has no element
        root = new;
        cur = root;
        prev = NULL;
    } else {
        new->next = cur;
        prev->next = new;
        cur = prev->next;
    }
}

void traversingList(){
    node_addr* p;
    for (p = root; p != NULL; p = p->next){
        displayNode(p);
    }
}

void deleteFirstElement(){
    node_addr *del = root;

    if (del == NULL)
        return;
    root = del->next;
    free(del);
    cur = root;
    prev = NULL;
}

void deleteCurrentElement(){
    node_addr *del = cur;

    if (cur == NULL)
        return;
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

void freeList(){
    node_addr *to_free;
    to_free = root;

    while (to_free != NULL){
        root = root->next;
        free(to_free);
        to_free = root;
    }
}

node_addr *list_reverse (){
    node_addr *cur, *prev;
    cur = prev = NULL;
    while (root != NULL) {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

int main(){

    address tmp = readNode();
    address tmp2 = readNode();
    address tmp3 = readNode();
    address tmp4 = readNode();

    root = makeNewNode(tmp);

    insertAtHead(tmp2);
    printf("\n");
    traversingList();
    insertAfterCurrent(tmp3);
    printf("\n");
    traversingList();
    insertBeforeCurrent(tmp4);
    printf("\n");
    traversingList();
    deleteFirstElement();
    printf("\n");
    traversingList();

    printf("before:\n");
    traversingList();

    root = list_reverse();
    printf("after: \n");
    traversingList();

    freeList();
    printf("\n");
    traversingList();
    return 0;
}
