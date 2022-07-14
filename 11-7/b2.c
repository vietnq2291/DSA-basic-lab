#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50

typedef struct road_t {
    char path[500];
    float len;
} Road;

void print_reversed(Road road_list[], int n) {
    char *path_segment;  
    char tmp_str[100];
    Road road_list_reversed[MAX];

    for (int i = 0; i < n; i++) {
        char segment_list[MAX][100];
        
        path_segment = strtok(road_list[i].path, "$");
   
        int m = 0;
        while(path_segment != NULL ) {
            
            if (isalpha(path_segment[0]) && isdigit(path_segment[strlen(path_segment)-1])) {
                strcpy(segment_list[m], path_segment);
            } else if (isdigit(path_segment[0])) {
                strcpy(tmp_str, "-");
                strcat(tmp_str, path_segment);
                strcpy(segment_list[m], tmp_str);
            } else {
                strcpy(segment_list[m], path_segment);
            }

            path_segment = strtok(NULL, "$");
            m++;
        }
        
        char reversed_path[500];  
        strcpy(reversed_path, "$");
        for (int j = m-1; j >= 0; j--) {
            strcat(reversed_path, segment_list[j]);
            strcat(reversed_path, "$");
        }

        // copy values
        strcpy(road_list_reversed[i].path, reversed_path);
        road_list_reversed[i].len = road_list[i].len;
    }

    // sort list
    Road tmp_road;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (road_list_reversed[i].len < road_list_reversed[j].len) {
                tmp_road = road_list_reversed[i];
                road_list_reversed[i] = road_list_reversed[j];
                road_list_reversed[j] = tmp_road;
            }
        }
    }

    // print list
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2f\n", road_list_reversed[i].path, road_list_reversed[i].len);
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
    char filename[] = "data.txt";
    if ((fptr = fopen(filename, "r")) == NULL) {
        printf("Failed openning file %s.\n", filename);
        return 1;
    }

    // read file content
    while (1) {
        fscanf(fptr,"%s", tmp_path);
        if (strcmp(tmp_path, "$") == 0) {
            break;
        }
        fscanf(fptr, "%f", &tmp_len);
        

        strcpy(road_list[n].path, tmp_path);
        road_list[n].len = tmp_len;
        n++;
    }

    // calculate total length
    print_reversed(road_list, n);
    

    return 0;
}