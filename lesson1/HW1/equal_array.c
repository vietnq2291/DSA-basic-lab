#include<stdio.h>
const int SIZE = 20;

int equal_array(int arr1[], int arr2[], int n){
    /*
     * return 1 if 2 arrays are equal
     * return -1 if 2 arrays are symmetric
     * return 0 otherwise
     */

    for (int i = 0; i < n; i++){
        if (arr1[i] != arr2[i]){
            for (int j = 0; j < n; j++){
                if (arr1[j] != arr2[n-j-1]){
                    return 0;
                }
            }
            return -1;
        }
    }
    return 1;
}

int main(){
    int arr1[SIZE], arr2[SIZE];
    int n1, n2;

    // Get array 1 input
    printf("Length of first array: ");
    scanf("%d", &n1);
    printf("Enter array elements: ");
    for (int i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }

    // Get array 2 input
    printf("Length of second array: ");
    scanf("%d", &n2);
    printf("Enter array elements: ");
    for (int i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }

    // Check for equality
    int equality = equal_array(arr1, arr2, n1);
    if (n1 != n2 || (equality == 0)){
        printf("This 2 arrays are not equal!\n");
    } else if (equality == 1){
        printf("This 2 arrays are equal\n");
    } else if (equality == -1){
        printf("This 2 arrays are symmetric\n");
    }

    return 0;
}
