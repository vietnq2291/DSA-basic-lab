#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *str;

    // initial memory allocation
    str = (char *) malloc(15);
    strcpy(str, "12345678901234567abc");
    printf("String = %s, Address = %p, %ld\n", str, str, sizeof(str));

    // Reallocating memory
    str = (char *) realloc(str, 25);
    printf("String = %s, Address = %p\n", str, str);
    
    free(str);

    return 0;
}
