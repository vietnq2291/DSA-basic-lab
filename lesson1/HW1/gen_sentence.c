#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WORD_LEN 20
#define LIST_SIZE 100

char *rand_word(char word_list[][WORD_LEN], int size){
    int i = rand() % size;
    return word_list[i];
}

int main(){
    char article[][WORD_LEN] = {"the", "a", "one", "some", "any"},
        noun[][WORD_LEN] = {"boy", "girl", "dog", "town", "car"},
        verb[][WORD_LEN] = {"drove", "jumped", "ran", "walked", "skipped"},
        prep[][WORD_LEN] = {"to", "from", "over", "on", "under"};
    int n, size[LIST_SIZE];

    // Seed for random generator
    srand(time(0));

    // Get number of sentence to generate
    printf("Number of sentence to generate: ");
    scanf("%d", &n);

    // Generate random words and print out
    for (int k = 0; k < n; k++){
        printf("#%d: ", k+1);
        printf("%s ", rand_word(article,sizeof(article)/sizeof(article[0])));
        printf("%s ", rand_word(noun, sizeof(noun)/sizeof(noun[0])));
        printf("%s ", rand_word(verb, sizeof(verb)/sizeof(verb[0])));
        printf("%s ", rand_word(prep, sizeof(prep)/sizeof(prep[0])));
        printf("%s ", rand_word(article,sizeof(article)/sizeof(article[0])));
        printf("%s", rand_word(noun, sizeof(noun)/sizeof(noun[0])));
        printf(".\n");
    }

    return 0;
}
