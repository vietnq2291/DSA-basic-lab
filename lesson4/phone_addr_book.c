#include<stdio.h>
#include<stdlib.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneaddress_t {
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(){
    int n=10, irc;
    int reval = SUCCESS;
    FILE *fptr;
    char filename[] = "phonebook.dat";
    phoneaddress phonearr[MAX_ELEMENT], // array to store input data
                 phonearr2[MAX_ELEMENT];// array to store read data from .dat file


    // input data to array from console
    for (int i = 0; i < n; i++){
        printf("Enter contact #%d:\n", i + 1);
        printf("- Name: "); scanf(" %[^\n]19s", phonearr[i].name);
        printf("- Telephone number: "); scanf("%10s", phonearr[i].tel);
        printf("- e-mail address: "); scanf("%24s", phonearr[i].email);
    }

    // open file to write data
    if ((fptr = fopen(filename, "wb")) == NULL){
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        // write data into phonebook.dat
        irc = fwrite(phonearr, sizeof(phoneaddress), n, fptr);
        printf(" fwrite return code: %d\n", irc);
        fclose(fptr);
        
        // open file to read data
        if ((fptr = fopen(filename, "rb")) == NULL){
            printf("Cannot open %s.\n", filename);
            reval = FAIL;
        } else {
            // read data from phonebook.dat
            irc = fread(phonearr2, sizeof(phoneaddress), n, fptr);
            printf(" fread return code: %d\n", irc);

            // print read data
            for (int i = 0; i < n; i++){
                printf("%-20s \t %-10s \t %-25s\n", phonearr2[i].name, phonearr2[i].tel, phonearr2[i].email);
            }
        }
    }

    return reval;
}