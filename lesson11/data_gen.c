#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
    FILE *fptr;
    int rand_num, n, m, M;
    char filename[] = "arr-n.txt";

    if (argc != 4) {
        printf("Wrong number of arguments\n");
        printf("The correct syntax is: data_gen <n> <m> <M>\n");
        return 1;
    }

    // get n and random range
    filename[4] = argv[1][0];
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    M = atoi(argv[3]);

    // open file
    if ((fptr = fopen(filename, "w")) == NULL) {
        printf("Cannot open file %s\n.", filename);
        return 1;
    }


    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        rand_num = rand() % (M - m) + m;
        fprintf(fptr, "%d ", rand_num);
    }

    return 0;
}
