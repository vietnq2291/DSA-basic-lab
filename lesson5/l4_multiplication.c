#include<stdio.h>

int multiply(int a, int b){
    if (b == 1)
        return a;
    return a + multiply(a, b-1);
}

int main(){
    int a, b;

    printf("a = "); scanf("%d", &a);
    printf("b = "); scanf("%d", &b);

    printf("%d\n", multiply(a, b));
    return 0;
}
