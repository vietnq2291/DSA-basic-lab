#include<stdio.h>

void replace_char(char *sptr, char ch1, char ch2){
    if (sptr == NULL)
        return;

    while (*sptr != '\0'){
        if (*sptr == ch1)
            *sptr = ch2;
        sptr++;
    }
}

int main(){
    char str[100];

    // Get input
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    // Replace characters
    char ch1 = 'a';
    char ch2 = 'A';
    replace_char(str, ch1, ch2);
    printf("Replaced string: %s\n", str);

    return 0;
}
