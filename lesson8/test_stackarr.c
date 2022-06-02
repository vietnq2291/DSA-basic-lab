#include "stack_improved.h"

int main(){
    int i;
    int arr[6] = {4, 6, 1, 3, -22, 14};
    StackType s;

    // print array
    for (i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    initalize(s);
    for (i = 0; i < 6; i++)
        push(arr[i], s);

    printf("Pop all element in stack:\n");
    while (!is_empty(s)){
        printf("%d ", pop(s));
    }
    printf("\n");

    return 0;
}
