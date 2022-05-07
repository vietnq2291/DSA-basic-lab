#include<stdio.h>

int digit_count(int n){
    if (n < 1)
        return 0;
    return 1 + digit_count(n/10);
}

int sum(int n){
    if (n == 0)
        return 0;
    return (n % 10) + sum(n/10);
}

int main(){
    int n;

    printf("n = "), scanf("%d", &n);

    printf("Number of digits: %d\n", digit_count(n));
    printf("Sum of all digits: %d\n", sum(n));

    return 0;
}
