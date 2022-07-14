#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"stacklist.h"
#define MAX 30

StackType top = NULL;

int prior(char operator) {
    if (operator == '(' || operator == ')')
        return 4;
    else if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

void convert_to_postfix(char input[], char output[], StackType *s) {
    int i=0, read=0;
    char ele;

    while ((ele = input[i]) != '\0') {
        if (isdigit(ele)) {
            output[read++] = ele;
        } else if (prior(ele) == 0) {
            printf("Wrong expression!\n");
            return;
        } else {

            // push operator to stack
            if (ele == ')') {
                while (peek(*s) != '(') {
                    output[read++] = pop(s);
                }
                pop(s);
            } else {
                if ((prior(ele) <= prior(peek(*s))) && peek(*s) != '(') {
                    output[read++] = pop(s);
                }
                push(ele, s);
            }
        }
        i++;
    }

    while (!is_empty(*s))
        output[read++] = pop(s);
    output[read] = '\0';

    printf("Postfix expression: %s\n", output);
}

void calculate_postfix(char expr[], StackType *s) {
    int result;
    int num1, num2;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(expr[i], s);
            continue;
        }

        // calculate current operation
        num2 = pop(s) - '0';
        num1 = pop(s) - '0';
        if (expr[i] == '+')
            result = num1 + num2;
        else if (expr[i] == '-')
            result = num1 - num2;
        else if (expr[i] == '*')
            result = num1 * num2;
        else if (expr[i] == '/')
            result = num1 / num2;

        // add result to stack
        result += '0';
        if (result < '0' || result > '9') {
            printf("Out of range\n");
            return;
        }
        push(result, s);
    }
    printf("Result: %c\n", pop(s));
}

void print_menu() {
    printf("\n *** Calculator in range(10) ***\n\n");
    printf("1. Enter arithmetic expressions in infix notation\n");
    printf("2. Change to postfix form\n");
    printf("3. Calculating value\n");
    printf("4. Exit\n");
    printf("=> You choose: ");
}

int main(){
    char input[MAX], output[MAX]="";
    StackType s=NULL;
    int user_choice;

    do {
        print_menu();
        scanf("%d", &user_choice); getchar();

        switch(user_choice) {
            case 1:
                printf("Enter infix expression: "); scanf("%[^\n]", input);
                break;
            case 2:
                convert_to_postfix(input, output, &s);
                break;
            case 3:
                calculate_postfix(output, &s);
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
