#include<stdio.h>
#include<string.h>
#define SIZE 10

int main(){
    char lst[][10] = {"to", "from", "over", "on", "under"};

    printf("%lu\n", sizeof(lst)/sizeof(lst[0]));
    return 0;

}
