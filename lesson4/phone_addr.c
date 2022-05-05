#include<stdio.h>

enum {SUCCESS, FAIL, MAX_ELEMENT=20};

// The phone book structure
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(){
    phoneaddress phonearr[MAX_ELEMENT],
                 pharr2[MAX_ELEMENT];
    FILE *fp;
    char fin_name[]="input.txt";
    int i, n, irc;
    int reval = SUCCESS;

    printf("How many contact do you want to enter (<20)?");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("name: "); scanf("%s", phonearr[i].name);
        printf("tel: "); scanf("%s", phonearr[i].tel);
        printf("email: "); scanf("%s", phonearr[i].email);
    }

    if ((fp = fopen("phonebook.dat", "w+b")) == NULL){
        printf("Cannot open %s\n", "phonebook.dat");
        reval = FAIL;
    }

    // write the entire array into the file
    irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);

    // read from this file to array again
    if ((fp = fopen("phonebook.dat", "rb")) == NULL){
        printf("Cannot open %s.\n", "phonebook.dat");
        reval = FAIL;
    }

    irc = fread(pharr2, sizeof(phoneaddress), n, fp);
    printf("fread return code = %d\n", irc);

    for (i = 0; i < n; i++){
        printf("%s-", pharr2[i].name);
        printf("%s-", pharr2[i].tel);
        printf("%s\n", pharr2[i].email);
    }
    fclose(fp);
    return reval;
}
