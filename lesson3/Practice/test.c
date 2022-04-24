#include<stdio.h>

int main(){
    int a[7] = {1, 2, 5};
    int *p;
    p = a;

    printf("%d\n", a[2]);
    printf("a=%ld, p=%ld\n", sizeof(a), sizeof(p));
    return 0;
}
