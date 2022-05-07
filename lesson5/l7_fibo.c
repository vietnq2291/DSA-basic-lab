#include<stdio.h>

void fibo(int num1, int num2, int count, int n){
    if (count <= n){
        printf("%d ", num2);
        fibo(num2, num1+num2, ++count, n);
    }
}

int fac(int n){
    if (n == 0)
        return 1;
    return n * fac(n-1);
}

int main(){
    int n;

    printf("n = "); scanf("%d", &n);
    printf("Fibonacci series: ");
    fibo(0, 1, 1, n);

    printf("\nFactorial n! = %d\n", fac(n));

    return 0;
}
