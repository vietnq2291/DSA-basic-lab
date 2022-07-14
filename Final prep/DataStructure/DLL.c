#include<stdio.h>
#include<stdlib.h>

// define element type & Node -------------------------------------------------
typedef struct{
    // define element type here...
    int num;
} ElementType;

typedef struct Node_t {
    ElementType element;
    struct Node_t *next;
    struct Node_t *prev;
} Node;

typedef Node *DoubleList;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    printf("Input data: "); scanf("%d", &e.num);
    return e;
}

void print_data(ElementType e) {
    printf("%3d", e.num);
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

void make_null_list(DoubleList *root, DoubleList *tail, DoubleList *cur) {
    (*root) = NULL;
    (*cur) = NULL;
    (*tail) = NULL;
}

int is_empty(DoubleList root) {
    return (root == NULL);
}

Node *insert_at_head(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* return pointer to new node
     * if failed, return NULL 
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert to empty list
    if (is_empty(*root)) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return new;
    }

    new->next = (*root);
    (*root)->prev = new;
    (*root) = new;
    (*cur) = new;
    return new;
}

Node *insert_at_tail(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* return pointer to new node
     * if failed, return NULL 
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert to empty list
    if (is_empty(*root)) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return new;
    }

    (*tail)->next = new;
    new->prev = (*tail);
    (*tail) = new;
    (*cur) = new;
    return new;
}

Node *insert_after_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* return pointer to new node
     * if failed, return NULL 
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert into empty list
    if (is_empty(*root)) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return new;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return NULL;
    }

    new->next = (*cur)->next;
    if ((*cur)->next != NULL) 
        (*cur)->next->prev = new; // if current is not tail, update next node's prev pointer
    else 
        (*tail) = new; // if current is tail, update tail pointer

    (*cur)->next = new;
    new->prev = (*cur);
    (*cur) = new;
    return new;
}

Node *insert_before_current(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* return pointer to new node
     * if failed, return NULL 
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert into empty list
    if (is_empty(*root)) {
        (*root) = new;
        (*cur) = new;
        (*tail) = new;
        return new;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return NULL;
    }

    new->next = (*cur);
    new->prev = (*cur)->prev;
    if ((*cur) != (*root)) 
        (*cur)->prev->next = new; // if current is not head, update prev node's next pointer
    else
        (*root) = new; // if current is head, update root pointer
    (*cur)->prev = new;    
    (*cur) = new;
    return new;
}

Node *insert_at_position(ElementType e, int n, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* Insert new node at position n
     * return pointer to new node
     * if failed, return NULL 
     */
    // out of index n
    if (n < 0) {
        printf("Out of index n!\n");
        return NULL;
    }

    // insert at head
    if (n == 0 || is_empty(*root)) {
        insert_at_head(e, root, tail, cur);
        return (*root);
    }

    // traverse the list to get the nth node
    Node *temp_cur = (*root);
    for (int i = 0; i < n-1; i++){
        if (temp_cur->next == NULL){
            printf("Out of index n!\n");
            return NULL;
        }
        temp_cur = temp_cur->next;
    }
    (*cur) = temp_cur;
    return insert_after_current(e, root, tail, cur);
}

Node *delete_at_position(int n, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* Delete node at position n -> free memory of deleted node
     * return pointer to root node if success
     * if failed, return NULL 
     * if cur pointer is deleted, set cur pointer to root 
     */
    Node *temp_cur =  *root;

    // empty list
    if (is_empty(*root)) {
        printf("Empty list!\n");
        return NULL;
    }

    // invalid index
    if (n < 0) {
        printf("Out of index n!\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (temp_cur->next == NULL){
            printf("Out of index n!\n");
            return NULL;
        }
        temp_cur = temp_cur->next;
    }

    // check if deleting root node
    if (temp_cur == (*root)) (*root) = temp_cur->next;
    else temp_cur->prev->next = temp_cur->next;
    // check if deleting tail node
    if (temp_cur->next != NULL) temp_cur->next->prev = temp_cur->prev;
    else (*tail) = temp_cur->prev;

    // check if deleting current node
    if (temp_cur == (*cur)) (*cur) = (*root);

    free(temp_cur);

    return (*root);
}

Node *delete_element(ElementType e, DoubleList *root, DoubleList *tail, DoubleList *cur) {
    /* Delete element e from list -> free memory of deleted node
     * return pointer to root node if success
     * if failed, return NULL 
     * if cur pointer is deleted, set cur pointer to root 
     */
    Node *temp_cur;
    for (temp_cur = (*root); temp_cur != NULL; temp_cur = temp_cur->next){
        if (temp_cur->element.num == e.num){
            // check if deleting root node
            if (temp_cur == (*root)) (*root) = (*root)->next;
            else temp_cur->prev->next = temp_cur->next;
            // check if deleting tail node
            if (temp_cur->next != NULL) temp_cur->next->prev = temp_cur->prev;
            else (*tail) = temp_cur->prev;
            break;
        }
    }

    if (temp_cur == NULL){
        printf("Element not found!\n");
        return NULL;
    }

    // check if deleting current node
    if (temp_cur == (*cur)) (*cur) = (*root);

    free(temp_cur);

    return (*root);
}

Node *search(int to_search, DoubleList *root, DoubleList *cur) {
    /* Search for element with num = to_search -> set cur pointer to found node
     * return pointer to node if found
     * if failed, return NULL
     */
    Node *temp_cur;
    int i=0;

    for (temp_cur = (*root); temp_cur != NULL; i++){
        if (temp_cur->element.num == to_search) {
            printf("Found at index: %d\t", i);
            print_data(temp_cur->element);
            printf("\n");
            
            (*cur) = temp_cur;
            return (*cur);
        }
        temp_cur = temp_cur->next;
    }

    printf("Element not found!\n");
    return NULL;
}

Node *reverse_list(DoubleList *root, DoubleList *tail) {
    /* Reverse the list -> return pointer to root node
     * if failed, return NULL 
     */
    Node *temp, *p = (*root);

    // empty list
    if (is_empty(*root)) {
        printf("Empty list!\n");
        return NULL;
    }

    // reverse root and tail node
    temp = (*root);
    (*root) = (*tail);
    (*tail) = temp;

    // reverse the list
    while (p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
    }
    return (*root);
}

void traverse_list(DoubleList root, DoubleList tail, int reverse) {
    /* Traverse the list
     * if reverse = 0, traverse from head to tail
     * if reverse = 1, traverse from tail to head
     */
    Node *p;

    if (is_empty(root)) {
        printf("Empty list!\n");
        return;
    }

    if (reverse == 0) {
        for (p = root; p != NULL; p = p->next) {
            print_data(p->element);
        }
    } else {
        for (p = tail; p != NULL; p = p->prev) {
            print_data(p->element);
        }
    }
    printf("\n");
}


DoubleList root, tail, cur;


int main(){
//    ElementType e1 = read_data();
//    Node *n1 = make_new_node(e1);
//    ElementType e2 = read_data();
//    Node *n2 = make_new_node(e2);
//    ElementType e3 = read_data();
//    Node *n3 = make_new_node(e3);
//    ElementType e4 = read_data();
//    Node *n4 = make_new_node(e4);
//    ElementType e5 = read_data();
//    Node *n5 = make_new_node(e5);

    make_null_list(&root, &tail, &cur);

    ElementType e1 = read_data();
    ElementType e2 = read_data();
    ElementType e3 = read_data();
    ElementType e4 = read_data();
    ElementType e5 = read_data();
//    ElementType e6 = read_data();
//    ElementType e7 = read_data();
//    ElementType e8 = read_data();

    make_null_list(&root, &tail, &cur);

    printf("list:\n");
    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);

    insert_at_head(e1, &root, &tail, &cur);
    printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);

    Node *n2 = insert_after_current(e2, &root, &tail, &cur);
    printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);

    insert_after_current(e3, &root, &tail, &cur);
    printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);
    // cur = n2;

    insert_before_current(e4, &root, &tail, &cur);
    printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);

    // int index; scanf("%d", &index);
    cur = tail;
    insert_before_current(e5, &root, &tail, &cur);
    printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
    traverse_list(root, tail, 0);
    traverse_list(root, tail, 1);

    make_null_list(&root, &tail, &cur);
    while(1){
        printf("is empty: %d\n", is_empty(root));
        // delete_element(read_data(), &root);
        int n1;
        scanf("%d", &n1); 
        // if (n1 == -1)
        //     reverse_list(&root, &tail);
        // else
            printf("deleted: %p\n", search(n1, &root, &cur));
        printf("root: %p -> %d, tail: %p -> %d, cur: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    tail, (tail == NULL) ? -1 : tail->element.num,
                    cur, (cur == NULL) ? -1 : cur->element.num);
        traverse_list(root, tail, 0);
        traverse_list(root, tail, 1);
    }

    // insert_before_current(e4, &root, &tail, &cur);

    // printf("list:\n");
    // printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    // traverse_list(root);

    // make_null_list(&root, &tail, &cur);
    // printf("before\n");
    // list_reverse(&root, &tail);
    // printf("ok\n");
    // printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    // traverse_list(root);
//    insert_after_current(e6, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);
//    insert_after_current(e7, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);
//    insert_after_current(e8, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);


    return 0;
}