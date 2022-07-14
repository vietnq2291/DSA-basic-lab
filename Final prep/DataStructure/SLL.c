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
} Node;

typedef Node *SingleList;

// ElementType functions-------------------------------------------------------
ElementType read_data() {
    ElementType e;
    printf("Input data: "); scanf("%d", &e.num);
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

Node *insert_at_head(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    /* return pointer to new node
     * if failed, return NULL
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert to empty list
    if ((*root) == NULL) {
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return new;
    }

    new->next = (*root);
    (*root) = new;
    (*cur) = new;
    (*prev) = NULL;
    return new;
}

Node *insert_after_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    /* return pointer to new node
     * if failed, return NULL
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return new;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return NULL;
    }

    new->next = (*cur)->next;
    (*cur)->next = new;
    (*prev) = (*cur);
    (*cur) = new;
    return new;
}

Node *insert_before_current(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    /* return pointer to new node
     * if failed, return NULL
     */
    Node *new = make_new_node(e);

    if (new == NULL){
        printf("Make new node failed!\n");
        return NULL;
    }

    // insert into empty list
    if ((*root) == NULL){
        (*root) = new;
        (*cur) = new;
        (*prev) = NULL;
        return new;
    }

    // current pointer points to NULL
    if ((*cur) == NULL){
        printf("Cannot insert new Node - Current pointer points to NULL!\n");
        return NULL;
    }

    new->next = (*cur);
    if ((*cur) == (*root)) (*root) = new;
    else (*prev)->next = new;
    (*cur) = new;
    return new;
}

Node *insert_at_position(ElementType e, int n, SingleList *root, SingleList *cur, SingleList *prev) {
    /* Insert new node at index n (head is 0)
     * return pointer to new node
     * if failed, return NULL
     */
    // out of index n
    if (n < 0) {
        printf("Out of index!\n");
        return NULL;
    }

    // insert at head
    if (n == 0 || is_empty(*root)) {
        insert_at_head(e, root, cur, prev);
        return (*root);
    }

    // traverse the list to get the nth node
    Node *temp_cur = (*root),
         *temp_prev = NULL;
    for (int i = 0; i < n-1; i++) {
        if (temp_cur->next == NULL) {
            printf("Out of index!\n");
            return NULL;
        }
        temp_prev = temp_cur;
        temp_cur = temp_cur->next;
    }
    (*prev) = temp_prev;
    (*cur) = temp_cur;
    return insert_after_current(e, root, cur, prev);
}

Node *delete_at_position(int n, SingleList *root, SingleList *cur, SingleList *prev) {
    /* Delete node at index n (head is 0) -> free memory of deleted node
     * return pointer to root node if success
     * if failed, return NULL
     * if cur pointer is deleted, set cur to root node & prev to NULL
     */
    Node *temp_cur =  *root,
         *temp_prev = NULL;

    // empty list
    if ((*root) == NULL) {
        printf("Empty list!\n");
        return NULL;
    }

    // invalid index
    if (n < 0) {
        printf("Out of index!\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (temp_cur->next == NULL){
            printf("Out of index!\n");
            return NULL;
        }
        temp_prev = temp_cur;
        temp_cur = temp_cur->next;
    }

    if (temp_cur == (*root)) (*root) = temp_cur->next;
    else temp_prev->next = temp_cur->next;

    // update current pointer & previous pointer
    if ((*cur) == temp_cur) {
        // current pointer is deleted
        (*cur) = (*root);
        (*prev) = NULL;
    } else if ((*cur) == temp_cur->next) {
        // previous pointer is deleted
        (*prev) = temp_prev;
    }
    free(temp_cur);
    return (*root);
}

Node *delete_element(ElementType e, SingleList *root, SingleList *cur, SingleList *prev) {
    /* Delete element e from list -> free memory of deleted node
     * return pointer to root node if success
     * if failed, return NULL
     * if cur pointer is deleted, set cur to root node & prev to NULL
     */
    Node *temp_cur, *temp_prev;
    for (temp_cur = (*root); temp_cur != NULL; temp_cur = temp_cur->next){
        if (temp_cur->element.num == e.num){
            if (temp_cur == (*root)) 
                (*root) = (*root)->next;
            else 
                temp_prev->next = temp_cur->next;
            break;
        }
        temp_prev = temp_cur;
    }

    if (temp_cur == NULL) {
        printf("Element not found!\n");
        return NULL;
    }

    // update current pointer & previous pointer
    if ((*cur) == temp_cur) {
        // current pointer is deleted
        (*cur) = (*root);
        (*prev) = NULL;
    } else if ((*cur) == temp_cur->next) {
        // previous pointer is deleted
        (*prev) = temp_prev;
    }
    free(temp_cur);
    return (*root);
}

Node *search(int to_search, SingleList *root, SingleList *cur, SingleList *prev) {
    /* Search for element with num = to_search -> set cur pointer to found node
     * return pointer to node if found
     * if failed, return NULL
     */
    Node *temp_cur, *temp_prev=NULL;
    int i=0;

    for (temp_cur = (*root); temp_cur != NULL; i++){
        if (temp_cur->element.num == to_search) {
            printf("Found at index: %d\t", i);
            print_data(temp_cur->element);
            printf("\n");

            (*prev) = temp_prev;
            (*cur) = temp_cur;
            return (*cur);
        }
        temp_prev = temp_cur;
        temp_cur = temp_cur->next;
    }

    printf("Element not found!\n");
    return NULL;
}

Node *split_list(int n1, int n2, SingleList *root, SingleList *cur, SingleList *prev) {
    Node *temp_cur = *root,
         *prev_slist = NULL,
         *sublist = NULL;

    // list of 0 elements
    if (n2 <= 0) {
        printf("Sublist of 0 elements!\n");
        return NULL;
    }

    // invalid index
    if (n1 < 0) {
        printf("Out of index!\n");
        return NULL;
    }

    // find head of sublist
    for (int i = 0; i < n1; i++) {
        if (temp_cur->next == NULL){
            return sublist;
        }
        prev_slist = temp_cur;
        temp_cur = temp_cur->next;
    }
    sublist = temp_cur;

    // traverse the sublist
    for (int i = 0; i < n2-1; i++) {
        if (temp_cur->next == NULL) {
            break;
        }
        temp_cur = temp_cur->next;
    }

    if (prev_slist != NULL) prev_slist->next = temp_cur->next;
    else (*root) = temp_cur->next;
    temp_cur->next = NULL;

    // update current pointer & previous pointer
    if ((*cur) == sublist) {
        // prev pointer is no longer be the previous node of cur pointer
        (*prev) = NULL;
    }

    return sublist;
}

Node *reverse_list(SingleList *root, SingleList *cur, SingleList *prev) {
    /* Reverse the list -> return pointer to new root node
     * if failed, return NULL
     */

    if (root == NULL) {
        printf("Empty list!\n");
        return NULL;
    }

    Node *temp_cur, *temp_prev;
    temp_cur = temp_prev = NULL;
    while ((*root) != NULL) {
        temp_cur = (*root);
        (*root) = (*root)->next;
        temp_cur->next = temp_prev;
        temp_prev = temp_cur;

        // update current pointer & previous pointer
        if ((*cur) == temp_cur) {
            (*prev) = (*root);
        }
    }
    (*root) = temp_prev;
    return (*root);
}

void traverse_list(SingleList root) {
    if (root == NULL) {
        printf("Empty list!\n");
        return;
    }

    for (Node *p = root; p != NULL; p = p->next){
        print_data(p->element);
    }
    printf("\n");
}



// driver program -----------------------------------------------------------
/* INSTRUCTION:
 * root, cur, prev are pointers to a node in the list.
 * - To modify value of them: pass by reference: function(&root, &cur, &prev)
 *      In the function(SingleList *root, SingleList *cur, SingleList *prev)
 *          -> root = &root; cur = &cur; prev = &prev;
 *          -> access their values by (*root), (*cur), (*prev)
 *                         ~ equivalent to root, cur, prev in main()
 *          -> or use them as pointers: root, cur, prev
 * - To get value without modifying them: pass by value: function(root, cur, prev)
 *      In the function(SingleList root, SingleList cur, SingleList prev)
 *          -> root = root; cur = cur; prev = prev;
 *          -> access their values by root, cur, prev
 * - To use them in main function:
 *          -> use root, cur, prev as pointers as usual
 * 
 * Errors may occur if the previous pointer is not updated properly along with the current pointer.
 */
SingleList root, cur, prev;


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

    make_null_list(&root, &cur, &prev);

    ElementType e1 = read_data();
    ElementType e2 = read_data();
    ElementType e3 = read_data();
    ElementType e4 = read_data();
    ElementType e5 = read_data();
    ElementType e6 = read_data();
    ElementType e7 = read_data();
    ElementType e8 = read_data();
    int n1, n2;
    Node *sublist;
    make_null_list(&root, &cur, &prev);
    printf("inserted: %p\n",insert_after_current(e1, &root, &cur, &prev));
    printf("root: %p, cur: %p, prev: %p\n", root, cur, prev);
    traverse_list(root);
    // cur = NULL;
    printf("inserted: %p\n",insert_after_current(e2, &root, &cur, &prev));
    printf("root: %p, cur: %p, prev: %p\n", root, cur, prev);
    traverse_list(root);
    // cur = root->next;
    // prev = root;
    printf("inserted: %p\n",insert_after_current(e3, &root, &cur, &prev));
    printf("root: %p, cur: %p, prev: %p\n", root, cur, prev);
    traverse_list(root);
    // cur = root->next;
    // prev = root;
    printf("inserted: %p\n",insert_at_position(e4, 2, &root, &cur, &prev));
    printf("root: %p, cur: %p, prev: %p\n", root, cur, prev);
    traverse_list(root);
    

    printf("inserted: %d -> %p\n", e5.num, insert_after_current(e5, &root, &cur, &prev));
    printf("inserted: %d -> %p\n", e6.num, insert_after_current(e6, &root, &cur, &prev));
    printf("inserted: %d -> %p\n", e7.num, insert_after_current(e7, &root, &cur, &prev));
    printf("inserted: %d -> %p\n", e8.num, insert_after_current(e8, &root, &cur, &prev));

    SingleList r2;
    traverse_list(root);
    printf("root: %p, cur: %p, prev: %p, root_sublist: %p\n", root, cur, prev, r2);
    r2 = split_list(6, 0, &root, &cur, &prev);
    traverse_list(root);
    traverse_list(r2);
    printf("root: %p, cur: %p, prev: %p, root_sublist: %p\n", root, cur, prev, r2);
    while(1){
        printf("is empty: %d\n", is_empty(root));
        // delete_element(read_data(), &root);
        scanf("%d", &n1); 
        if (n1 == -1)
            reverse_list(&root, &cur, &prev);
        printf("search for %d --> %p\n", n1, search(n1, &root, &cur, &prev));
        printf("root: %p -> %d, cur: %p -> %d, prev: %p -> %d\n", 
                    root, (root == NULL) ? -1 : root->element.num, 
                    cur, (cur == NULL) ? -1 : cur->element.num,
                    prev, (prev == NULL) ? -1 : prev->element.num);
        traverse_list(root);
    }

    return 0;
}
