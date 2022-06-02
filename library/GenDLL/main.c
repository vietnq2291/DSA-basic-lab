#include<stdio.h>
#include"GenDLL.h"

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
    traverse_list(root);

    insert_at_position(e1, 2, &root, &tail, &cur);
    printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    traverse_list(root);
    insert_after_current(e2, &root, &tail, &cur);
    printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    traverse_list(root);
    insert_at_head(e3, &root, &tail, &cur);
    printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    traverse_list(root);
    insert_before_current(e4, &root, &tail, &cur);

    printf("list:\n");
    printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    traverse_list(root);

    make_null_list(&root, &tail, &cur);
    printf("before\n");
    list_reverse(&root, &tail);
    printf("ok\n");
    printf("root: %d, tail: %d, cur: %d\n", root->element.num, tail->element.num, cur->element.num);
    traverse_list(root);
//    insert_after_current(e6, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);
//    insert_after_current(e7, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);
//    insert_after_current(e8, &root, &tail, &cur);
//    printf("root: %p, tail: %p, cur: %p\n", root, tail, cur);


    return 0;
}
