#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT=20};

// The phone book structure
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(){    
    FILE *fptr;
    char filename[] = "phonebook.dat";
    phoneaddress *data;
    int irc, reval = SUCCESS;
    int start_pos = 3, 
        end_pos = 6;
    int length = end_pos - start_pos + 1;

    

    // open file
    if ((fptr = fopen(filename, "r+b")) == NULL){
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    } else {
        // allocate memory for backup data
        data = (phoneaddress *) malloc(length * sizeof(phoneaddress));
        if(data == NULL){
            printf("Memory allocation failed!\n");
            reval = FAIL;
        }

        // Move cursor to beginning position of the read portion
        if (fseek(fptr, (start_pos - 1) * sizeof(phoneaddress), SEEK_SET) != 0){
            printf("fseek failed!\n");
            reval = FAIL;
        }
        
        // Read data
        irc = fread(data, sizeof(phoneaddress), length, fptr);
        printf(" fread return code: %d\n", irc);

        // Modify data
        for (int i = 0; i < length; i++){
            strcpy((data + i)->name, "..."); // instead of (data + i)->name, we can use: data[i].name
        }
        // strcpy(data[0].name, "Minh Nhat");
        // strcpy(data[1].name, "Nong Viet Dung");
        // strcpy(data[2].name, "Loving Hut");
        // strcpy(data[3].name, "Thai Ha"); 

        // Rewrite data to file
        fseek(fptr, (start_pos - 1) * sizeof(phoneaddress), SEEK_SET);
        fwrite(data, sizeof(phoneaddress), length, fptr);
        printf(" fwrite return code: %d\n", irc);

        fclose(fptr);
        free(data);
    }

    return reval;
}
