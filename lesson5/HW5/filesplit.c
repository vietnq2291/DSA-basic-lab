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
    FILE *fin, *fout1, *fout2;
    phoneaddress data[MAX_ELEMENT];

    // check arguments
    if (argc != 5){
        printf("The correct syntax is: filesplit <filename1> <no_of_contact> <filename2> <filename3>\n");
        reval = FAIL;
    } else if ((fin = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } else if ((fout1 = fopen(argv[3], "wb")) == NULL){
        printf("Cannot open %s.\n", argv[3]);
        reval = FAIL;
    } else if ((fout2 = fopen(argv[4], "wb")) == NULL){
        printf("Cannot open %s.\n", argv[4]);
        reval = FAIL;
    } else {
        n = atoi(argv[2]);
        irc = fread(data, sizeof(phoneaddress), MAX_ELEMENT, fin);

        fwrite(data, sizeof(phoneaddress), n, fout1);
        fwrite(data + n, sizeof(phoneaddress), irc - n, fout2);

        fclose(fin);
        fclose(fout1);
        fclose(fout2);
    }

    return reval;
}
