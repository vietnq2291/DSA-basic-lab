#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    char prev = '\0';

    // get input
    scanf("%[^\n]s", str);

    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' ' && prev != ' '){
            printf("\n");
        } else if (str[i] != ' ') {
            printf("%c", str[i]);
        }
        prev = str[i];
    }
    printf("\n");
    return 0;
}
