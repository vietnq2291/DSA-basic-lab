#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s1[]="hello_",
         s2[]="world!";
    char *str;

    // Initial memory allocation
    str = (char *) malloc(12);
    strcpy(str, s1);
    strcat(str, s2);

    printf("%s\n", str);
    return 0;
}
