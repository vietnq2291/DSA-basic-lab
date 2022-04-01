#include<stdio.h>
#define ALPHABET_LEN 26

int main(){
    char c;
    int count[ALPHABET_LEN] = {0};

    // read first character
    c = getchar();
    while (c != '\n' && c >= 0){
        if (c <= 'z' && c >= 'a'){
            ++count[c - 'a'];
        }
        c = getchar();
    }

    // Print duplicate number of characters
    for (int i = 0; i < ALPHABET_LEN; i++){
        if (count[i] > 0){
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
        }
    }

    return 0;
}
