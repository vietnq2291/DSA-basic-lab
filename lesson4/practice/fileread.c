#include<stdio.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(int argc, char* argv[]){
    int reval = SUCCESS;
    int irc;
    FILE *fptr;
    phoneaddress phonearr[MAX_ELEMENT];

    // check arguments
    if (argc != 2){
        printf("Wrong number of arguments!\n");
        printf("The correct syntax is: fileread <filename>\n");
        reval = FAIL;
    } else if ((fptr = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    } else {
        printf("   %-20s \t %-10s \t %-25s\n", "Name", "Phone number", "Email");

        // read data from file
        while (irc = fread(phonearr, sizeof(phoneaddress), MAX_ELEMENT, fptr)){
            for (int i = 0; i < irc; i++){
                printf("%2d %-20s \t %-10s \t %-25s\n", i+1, phonearr[i].name, phonearr[i].tel, phonearr[i].email);
            }
        }

        fclose(fptr);
    }

    return reval;
}