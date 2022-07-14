/*
 * implement a function that accepts 2 integer arrays
 * and return 1 if they are equal, -1 if they are symmetric, 0 otherwise (include empty arr)
 * The program get 2 arrays from user input and applies the function.
 */
#include<stdio.h>
#define MAX 100

int arrComp(int arr1[], int arr2[], int n1, int n2) {
    int res = 1;

    if (n1 != n2 || n1 == 0)
        return 0;

    if (arr1[0] != arr2[0]) {
        res = -1;
    }

    for (int i = 0; i < n1; i++) {
        if ((res == 1 && arr1[i] != arr2[i]) || (res == -1 && arr1[i] != arr2[n1-1-i])) {
            return 0;
        }
    }
    return res;
}

int main() {
    int n1, n2;
    int arr1[MAX], arr2[MAX];

    // get input
    scanf("%d%d", &n1, &n2);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // print result of comparation
    printf("%d\n", arrComp(arr1, arr2, n1, n2));

    return 0;
}


