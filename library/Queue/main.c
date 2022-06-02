#include<stdio.h>
#include"queueSLL.h"

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
    insert_after_current(e1, &root, &cur, &prev);
    insert_after_current(e2, &root, &cur, &prev);
    insert_after_current(e3, &root, &cur, &prev);
    insert_after_current(e4, &root, &cur, &prev);
    insert_after_current(e5, &root, &cur, &prev);
    insert_after_current(e6, &root, &cur, &prev);
    insert_after_current(e7, &root, &cur, &prev);
    insert_after_current(e8, &root, &cur, &prev);

    traverse_list(root);
    while(1){
        scanf("%d", &n1);
        delete_element(read_data(), &root);
        traverse_list(root);
    }

    return 0;
}
