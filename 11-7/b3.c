#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50

typedef struct road_t {
    char path[500];
    float len;
} Road;

typedef struct path_t {
    char ends[2][100];
    float len;
} Path;

void print_reversed(Road road_list[], int n) {
    char *path_segment;
    Path path_list[MAX];

    for (int i = 0; i < n; i++) {
        char segment_list[MAX][100];
        
        path_segment = strtok(road_list[i].path, "$");
   
        int m = 0;
        Path p;
        while(path_segment != NULL ) {
            
            if (isalpha(path_segment[0]) && isdigit(path_segment[strlen(path_segment)-1])) {
                strcpy(p.ends[m], path_segment);
                m++;
            }

            path_segment = strtok(NULL, "$");
        }
        p.len = road_list[i].len;
        path_list[i] = p;
    }

    // list of nodes
    char nodes[MAX][100];
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (path_list[i].ends[0] == nodes[j] || path_list[i].ends[1] == nodes[j]) {
                break;
            }
        }
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