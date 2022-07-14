/*
 * ask user to input a number of students, then their full name in VNese.
 * - print the student list sorted by their firstname.
 * - print the maximum number of students who have the same firstname
 */
#include<stdio.h>
#include<string.h>
#define MAX 50      // number of names
#define MAX_LEN 10  // number of word in a name

typedef struct name_t {
    int len;
    char wordList[MAX_LEN][256];
} Name;

void makeName(Name *name, char fullname[]) {
    int cnt = 0;
    char *word;

    // get words from name
    word = strtok(fullname, " ");
    while (word != NULL) {
        strcpy(name->wordList[cnt], word);
        word = strtok(NULL, " ");
        cnt++;
    }
    name->len = cnt;
}

void sort_names(Name nameList[], int n) {
    char firstname1[256],
         firstname2[256];
    char fullname1[256],
         fullname2[256];
    int changeCnt;

    for (int j = 0; j < n; j++) {
        changeCnt = 0;
        for (int i = 0; i < n-i-1; i++) {
            strcpy(firstname1, nameList[i].wordList[nameList[i].len - 1]);
            strcpy(firstname2, nameList[i+1].wordList[nameList[i].len - 1]);

            if (strcmp(firstname1, firstname2) > 0) {

            }
        }
        if (changeCnt == 0)
            break;
    }
}

int main() {
    int cnt, n;
    Name nameList[MAX];
    char s[][256] = {"Nguyen Bao Anh",
                      "Dao Thi Ha",
                      "Vuong Quoc Binh",
                      "Ngo Anh Vu",
                      "Tran Quang Binh"};

    // get input
    n = 5;
    for (int i = 0; i < n; i++) {
        makeName(&nameList[i], s[i]);
    }

    sort_names(nameList, n);

    for (int i = 0; i < n; i++) {
        printf("%d: ", nameList[i].len);
        for (int j = 0; j < nameList[i].len; j++) {
            printf("%s ", nameList[i].wordList[j]);
        }
        printf("\n");
    }

    return 0;
}
