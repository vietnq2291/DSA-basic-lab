#include<stdio.h>
#define MAX_ELEMENT 20

// The phone book structure
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(int argc, char *argv[]){
    phoneaddress phonearr[MAX_ELEMENT];
    FILE *fp;
    int i=0;

    if (argc != 2){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: fileread + <filename>\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    }

    while (!feof(fp)){
        printf("%ld", fread(phonearr, sizeof(phoneaddress), 1, fp));
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }
    fclose(fp);
    return 0;
}
