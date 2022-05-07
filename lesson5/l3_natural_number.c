#include<stdio.h>

//void triangular_num(int i, int n){
//    if (i <= n){
//        printf("%d ", i);
//        triangular_num(i+1, n);
//    }
//}

void triangular_num(int n){
    if (n != 0){
        triangular_num(n-1);
        printf("%d ", n);
    }
}

int main(){
    int n;

    // input n
    printf("n = ");
    scanf("%d", &n);

    printf("First %d natural numbers:\n", n);
//    triangular_num(1, n);
    triangular_num(n);
    printf("\n");
    return 0;
}
