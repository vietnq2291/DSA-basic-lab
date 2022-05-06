#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

char *my_strcat(char *str1, char *str2){
    int len1, len2;
    char *result;

    // get length of 2 strings
    len1 = strlen(str1);
    len2 = strlen(str2);

    // allocate a memory of total length of 2 strings + 1 for '/0'
    result = (char *) malloc((len1 + len2 + 1) * sizeof(char));

    if (result == NULL){
        printf("Allocation failed! Check memory\n");
        return NULL;
    }

    strcpy(result, str1);
    strcpy(result + len1, str2);

    return result;
}

int main(){
    char str1[MAX_LEN+1], str2[MAX_LEN+1];
    char *cat_str;

    printf("Please enter two strings\n");

    scanf("%100s", str1);
    scanf("%100s", str2);

    cat_str = my_strcat(str1, str2);
    if (cat_str == NULL){
        printf("Problem allocating memory!\n");
        return 1;
    }

    printf("The concatenation of %s and %s is %s\n", str1, str2, cat_str);

    free(cat_str);

    return 0;
}