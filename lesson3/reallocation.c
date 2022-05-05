#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *str;

    // Initial memory allocation
    str = (char *) malloc(15);
    strcpy(str, "tutorialpoint");
    printf("String = %s, Address = %u\n", str, str);

    // Reallocate memory
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s, Address = %u\n", str, str);
    
    return 0;
}