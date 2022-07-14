#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct road_t {
    char path[500];
    float len;
} Road;

void print_sorted(Road road_list[], int n) {
    // sort list
    char tmp_path[500];
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if (strcmp(road_list[i].path, road_list[j].path) > 0) {
                strcpy(tmp_path, road_list[i].path);
                strcpy(road_list[i].path, road_list[j].path);
                strcpy(road_list[j].path, tmp_path);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\t%.1f\n", road_list[i].path, road_list[i].len);
    }
}


int main() {
    FILE *fptr=stdin;
    Road road_list[MAX];
    char tmp_path[500];
    float tmp_len;
    float total_len;
    int n=0;

    // open file
    // char filename[] = "data.txt";
    // if ((fptr = fopen(filename, "r")) == NULL) {
    //     printf("Failed openning file %s.\n", filename);
    //     return 1;
    // }

    // read file content
    while (1) {
        fscanf(fptr, "%s", tmp_path);
        if (strcmp(tmp_path, "$") == 0) {
            break;
        }
        fscanf(fptr, "%f", &tmp_len);
        

        strcpy(road_list[n].path, tmp_path);
        road_list[n].len = tmp_len;
        n++;
    }

    // calculate total length
    total_len = 0;
    for (int i = 0; i < n; i++) {
        total_len += road_list[i].len;
    }

    printf("%d %.1f\n", n, total_len);
    print_sorted(road_list, n);
    

    return 0;
}