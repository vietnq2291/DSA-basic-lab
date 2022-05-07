#include<stdio.h>
#include<stdlib.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneaddress_t {
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(){
    int n, irc;
    int reval = SUCCESS;
    FILE *fptr;
    char filename[] = "phonebook.dat";
    phoneaddress phonearr[MAX_ELEMENT], // array to store input data
                 phonearr2[MAX_ELEMENT];// array to store read data from .dat file


    // input data to array from console
    printf("Number of contact: "); scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter contact #%d:\n", i + 1);
        printf("- Name: "); scanf(" %[^\n]19s", phonearr[i].name);
        printf("- Telephone number: "); scanf("%10s", phonearr[i].tel);
        printf("- e-mail address: "); scanf("%24s", phonearr[i].email);
    }

    // open file to write data
    if ((fptr = fopen(filename, "ab")) == NULL){
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        // write data into phonebook.dat
        irc = fwrite(phonearr, sizeof(phoneaddress), n, fptr);
        printf(" fwrite return code: %d\n", irc);
        fclose(fptr);
    }

    return reval;
}
