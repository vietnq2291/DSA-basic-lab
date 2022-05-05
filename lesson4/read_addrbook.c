#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {SUCCESS, FAIL, MAX_ELEMENT=20};

// The phone book structure
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(){
    phoneaddress *phonearr;
    FILE *fp;
    int i, n, irc;
    int reval = SUCCESS;
    char *portion;
    long start_pos = 2,
        end_pos = 4;

    if ((fp = fopen("phonebook.dat", "r+b")) == NULL){
        printf("Cannot open %s\n", "phonebook.dat");
        reval = FAIL;
    }

    // Memory allocation
    phonearr = (phoneaddress *) malloc(2 * sizeof(phoneaddress));
    if (phonearr == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    if (fseek(fp, start_pos*sizeof(phoneaddress), SEEK_SET) != 0){
        printf("Fseek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), (end_pos-start_pos), fp);

    for (i = 0; i < irc; i++){
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }

    // Modify data
    strcpy(phonearr[0].name, "Lan Hoa");
    strcpy(phonearr[0].tel, "0923456");
    strcpy(phonearr[0].email, "lovehut@gmail.com");

    fseek(fp, start_pos*sizeof(phoneaddress), SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), (end_pos-start_pos), fp);
    printf(" fwrite return code: %d\n", irc);

    fclose(fp);
    free(phonearr);
    return reval;
}
