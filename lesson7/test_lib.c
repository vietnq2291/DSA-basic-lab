#include "dllist_lib.h"


int main(){
    make_null_list(&root, &tail, &cur);

    // create elements
    elementtype e1 = read_data();
    elementtype e2 = read_data();
    elementtype e3 = read_data();
    elementtype e4 = read_data();
    elementtype e5 = read_data();

    // insert at head
    append(e1, &root, &tail, &cur);
    append(e2, &root, &tail, &cur);
    insert_at_head(e3, &root, &tail, &cur);
    insert_before_current(e5, &root, &tail, &cur);
    insert_after_current(e4, &root, &tail, &cur);

    traverse_list(&root);
    return 0;
}
