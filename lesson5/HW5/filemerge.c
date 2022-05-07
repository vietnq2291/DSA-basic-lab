#include<stdio.h>
#include<stdlib.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneaddress_t {
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(int argc, char *argv[]){
    int n, irc, reval = SUCCESS;
    FILE *fin1, *fin2, *fout;
    phoneaddress data[MAX_ELEMENT];

    // check arguments
    if (argc != 4){
        printf("The correct syntax is: filesplit <filesource1> <filesource2> <filedest>\n");
        reval = FAIL;
    } else if ((fin1 = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } else if ((fin2 = fopen(argv[2], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[2]);
        reval = FAIL;
    } else if ((fout = fopen(argv[3], "wb")) == NULL){
        printf("Cannot open %s.\n", argv[3]);
        reval = FAIL;
    } else {
        // read and write data from file 1 to destination file
        irc = fread(data, sizeof(phoneaddress), MAX_ELEMENT, fin1);
        fwrite(data, sizeof(phoneaddress), irc, fout);

        // read and write data from file 1 to destination file
        irc = fread(data, sizeof(phoneaddress), MAX_ELEMENT, fin2);
        fwrite(data, sizeof(phoneaddress), irc, fout);
        fclose(fin1);
        fclose(fin2);
        fclose(fout);
    }
    return reval;
}
