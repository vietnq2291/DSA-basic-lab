#include<stdio.h>

int triangular_num(int n){
    if (n == 1)
        return 1;
    else
        return n + triangular_num(n-1);
}

int main(){
    int n;

    // input n
    printf("n = ");
    scanf("%d", &n);

    printf("The nth term: %d\n", triangular_num(n));

    return 0;
}
