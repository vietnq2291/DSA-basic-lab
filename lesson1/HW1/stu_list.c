#include<stdio.h>
#include<string.h>

#define SIZE 10
#define NAME_LEN 50

void split_name(char fullname[][NAME_LEN], char first_name[][NAME_LEN], int n){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = strlen(fullname[i])-1; j >= 0; j--){
            if (fullname[i][j] == ' '){
                break;
            }
        }
        strcpy(first_name[i], &fullname[i][j+1]);
    }
}

void swap(char str1[], char str2[]){
    char tmp[NAME_LEN];

    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

void sort_name(char fullname[][NAME_LEN], char first_name[][NAME_LEN], int n){
    

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (strcmp(first_name[i], first_name[j]) >= 0){
                swap(first_name[i], first_name[j]);
                swap(fullname[i], fullname[j]);
            }
        }
    }
}

int count_rep(char first_name[][NAME_LEN], int n){
    int count, max_count=0;

    for (int i = 0; i < n-1; i++){
        count = 1;
        for (int j = i+1; j < n; j++){
            if (strcmp(first_name[i], first_name[j]) == 0){
                count++;
            }
        }

        if (count > max_count){
            max_count = count;
        }
    }

    return max_count;
}

int main(){
    char fullname[SIZE][NAME_LEN], first_name[SIZE][NAME_LEN];
    int n;

    // get student list from user input
    printf("Enter number of student: ");
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++){
        printf("- Student #%d: ", i+1);
        scanf("%[^\n]%*c", fullname[i]);
    }

    // generate list of student's first name, then sort student list in alphabet order
    split_name(fullname, first_name, n);
    sort_name(fullname, first_name, n);

    // print sorted list
    printf("\nSorted list of student:\n");
    for (int i = 0; i < n; i++){
        printf("- Student #%d: %s\n", i+1, fullname[i]);
    }
    // print most duplication
    printf("\nMaximum number of students who have the same first name: %d\n", count_rep(first_name, n));

    return 0;
}
