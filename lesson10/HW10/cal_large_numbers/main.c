#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stacklist.h"
#define MAX 30

void number_to_stack(char n[], StackType *s) {
    for (int i = 0; n[i] != '\0'; i++)
        push(n[i], s);
}

void add(char *res, StackType *s1, StackType *s2) {
    int i=0;
    int n1, n2, n0, carry=0;
    StackType sum=NULL;

    while (!is_empty(*s1) || !is_empty(*s2) || carry != 0) {
        if (!is_empty(*s1)) n1 = pop(s1) - '0';
        else n1 = 0;
        if (!is_empty(*s2)) n2 = pop(s2) - '0';
        else n2 = 0;

        n0 = n1 + n2 + carry + '0';
        if (n0 > '9') {
            carry = 1;
            n0 = n0 - 10;
        }
        else carry = 0;

        push(n0, &sum);
    }

    while (!is_empty(sum)) {
        res[i++] = pop(&sum);
    }
    res[i] = '\0';
}

void sub(char *res, StackType *s1, StackType *s2) {
    int i=0;
    int n1, n2, n0, carry=0;
    StackType sub=NULL;

    while (!is_empty(*s1) || !is_empty(*s2) || carry != 0) {
        if (!is_empty(*s1)) n1 = pop(s1) - '0';
        else n1 = 0;
        if (!is_empty(*s2)) n2 = pop(s2) - '0';
        else n2 = 0;

        n0 = n1 - n2 + carry + '0';
        if (n0 < '0') {
            carry = -1;
            n0 = n0 + 10;
        }
        else carry = 0;

        push(n0, &sub);
    }

    while (!is_empty(sub)) {
        res[i++] = pop(&sub);
    }
    res[i] = '\0';
}

void print_menu() {
    printf("\n *** Calculator with large number ***\n\n");
    printf("1. Enter numbers\n");
    printf("2. Addition\n");
    printf("3. Subtraction\n");
    printf("4. Exit\n");
    printf("=> You choose: ");
}

int main(){
    char n1[MAX], n2[MAX], res[MAX+1];
    StackType s1=NULL, s2=NULL;
    int user_choice;

    do {
        print_menu();
        scanf("%d", &user_choice); getchar();

        switch(user_choice) {
            case 1:
                printf("Enter 1st number: "); scanf("%s", n1);
                printf("Enter 2nd number: "); scanf("%s", n2);
                number_to_stack(n1, &s1);
                number_to_stack(n2, &s2);
                break;
            case 2:
                add(res, &s1, &s2);
                printf("%s + %s = %s\n", n1, n2, res);
                break;
            case 3:
                sub(res, &s1, &s2);
                printf("%s - %s = %s\n", n1, n2, res);
                break;
            case 4:
                printf("Good bye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (user_choice != 4);

    return 0;
}
