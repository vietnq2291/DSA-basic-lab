#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define WORD_LEN 20
#define LIST_SIZE 100

char *rand_word(char word_list[][WORD_LEN], int size){
    int i = rand() % size;
    return word_list[i];
}

int main(){
    char sentence[][LIST_SIZE][WORD_LEN] = {
        {"the", "a", "one", "some", "any"},
        {"boy", "girl", "dog", "town", "car"},
        {"drove", "jumped", "ran", "walked", "skipped"},
        {"to", "from", "over", "on", "under"}};
    char s[] = "";
    int n, len_list=LIST_SIZE/WORD_LEN;

    // Seed for random generator
    srand(time(0));

    // Get number of sentence to generate
    printf("Number of sentence to generate: ");
    scanf("%d", &n);

    // Generate random words and print out
    for (int k = 0; k < n; k++){
        printf("#%d:", k+1);
        for (int i = 0; i < 4; i++){
            printf(" %s", rand_word(sentence[i], len_list));
        }
        printf(".\n");
    }

    return 0;
}
