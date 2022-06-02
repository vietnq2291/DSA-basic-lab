#include "stack_improved.h"
#include<string.h>

void get_stack(char num[], StackType *s){
    push(2, *s);

}

int main(){
    char num1[1000], num2[1000];
    int len1, len2;
    StackType s1, s2;

    // get 2 number input
    printf("Enter 1st number: "); scanf("%s", num1);
    printf("Enter 2nd number: "); scanf("%s", num2);

    // Initialize stacks
    initalize(s1);
    initalize(s2);

    // store number in stack
    get_stack(num1, &s1);
    get_stack(num2, &s2);
    printf("%d\n", pop(s1));

    return 0;
}
