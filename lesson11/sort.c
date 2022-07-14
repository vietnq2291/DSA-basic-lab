#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_arr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Sorting algorithm ----------------------------------------------------------
void insertion_sort(int a[], int n) {
    printf("Implementing Insertion sort algorithm ...\n");
    int last, j;

    for (int i = 1; i < n; i++) {
        last = a[i];
        j = i;
        while (j > 0 && a[j-1] > last) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
}

void selection_sort(int a[], int n) {
    printf("Implementing Selection sort algorithm ...\n");
    int min, temp;

    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void bubble_sort(int a[], int n) {
    printf("Implementing Bubble sort algorithm ...\n");
    int swapped, temp;
    do {
        swapped = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swapped = 1;
            }
        }
    } while(swapped == 1);
}

void merge(int a[], int l, int m, int r) {
    int i = l;
    int j = m+1;
    int ta[r-l]; // temporary array

    for (int k = l; k <= r; k++) {
        if (i > m) {
            ta[k] = a[j];
            j++;
        } else if (j > r) {
            ta[k] = a[i];
            i++;
        } else {
            if (a[i] < a[j]) {
                ta[k] = a[i];
                i++;
            } else  {
                ta[k] = a[j];
                j++;
            }
        }
    }

    for (int k = l; k <= r; k++)
        a[k] = ta[k];
}
void merge_sort(int a[], int r, int l) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}


int main(int argc, char *argv[]) {
    FILE *fptr;
    int num, n;
    char filename[] = "arr-n.txt";
    if (argc != 3) {
        printf("Wrong number of arguments\n");
        printf("The correct syntax is: data_gen <sort_algorithm> <n>\n");
        return 1;
    }

    // open file
    filename[4] = argv[2][0];
    if ((fptr = fopen(filename, "r")) == NULL) {
        printf("Cannot open file %s\n.", filename);
        return 1;
    }

    // read array number from file
    n = atoi(argv[2]);
    int arr[n], i=0;
    while (fscanf(fptr, "%d", &num) != EOF) {
        arr[i++] = num;
    }

    // print before sorted
    printf("Before sorting: ");
    print_arr(arr, n);

    // call sorting algorithm
    if(strcmp(argv[1], "insertion_sort") == 0)
        insertion_sort(arr, n);
    else if(strcmp(argv[1], "selection_sort") == 0)
        selection_sort(arr, n);
    else if(strcmp(argv[1], "bubble_sort") == 0)
        bubble_sort(arr, n);
    else if(strcmp(argv[1], "merge_sort") == 0) {
        printf("Implementing Merge sort algorithm ...\n");
        merge_sort(arr, 0, n-1);
    }
    else {
        printf("Wrong insertion algorithm\n");
        return 1;
    }

    // print after sorted
    printf("After sorting:  ");
    print_arr(arr, n);

    return 0;
}
