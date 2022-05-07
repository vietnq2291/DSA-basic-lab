#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneInfo_t{
    char name[20];
    int memory;
    float screen;
    int price;
} phoneInfo;

int importDB(char filetxt[], char filedat[]){
    FILE *fin, *fout;
    phoneInfo *data;
    int n, count = 0;

    // open file
    if ((fin = fopen(filetxt, "r")) == NULL){
        printf("Cannot open %s.\n", filetxt);
        return -1;
    } else if ((fout = fopen(filedat, "wb")) == NULL){
        printf("Cannot open %s.\n", filedat);
        return -1;
    }

    // allocate memory
    data = (phoneInfo *) malloc(MAX_ELEMENT * sizeof(phoneInfo));

    // read data
    while(!feof(fin)){
        fscanf(fin, "- %s %d %f %d ", data[count].name, &data[count].memory, &data[count].screen, &data[count].price);
        count++;
    }

    // write data into .dat file
    fwrite(data, sizeof(phoneInfo), count, fout);

    printf("\nDatabase imported successfully!\n");
    printf("Data is stored in %s.\n", filedat);

    // Free memory and close files
    free(data);
    fclose(fin);
    fclose(fout);

    return count;
}

void readDB(int size, char filename[]){
    FILE *fin;
    phoneInfo *data;
    int n, irc, i=0;
    char read_mode;

    // open file
    if ((fin = fopen(filename, "rb")) == NULL){
        printf("Cannot open %s.\n", filename);
        return;
    }

    scanf(" %c", &read_mode);
    if (read_mode == 'F' || read_mode == 'f'){
        n = size;

        // allocate memory
        data = (phoneInfo *) malloc(size * sizeof(phoneInfo));
        if (data == NULL){
            printf("Memory allocation failed!\n");
            return;
        }
    } else {
        printf("- Number of records to read: "); scanf("%d", &n);

        // allocate memory
        data = (phoneInfo *) malloc(n * sizeof(phoneInfo));
        if (data == NULL){
            printf("Memory allocation failed!\n");
            return;
        }

        if (read_mode == 'E' || read_mode == 'e'){
            fseek(fin, (-n) * sizeof(phoneInfo), SEEK_END);
        } else if (read_mode != 'B' && read_mode != 'b'){
            printf("Invalid choice!\n");
            return;
        }
    }

    // Read data
    irc = fread(data, sizeof(phoneInfo), n, fin);
    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");

    while (i < irc){
        printf(" %-3d %-25s %6d %13.2f %16d\n", i+1, data[i].name, data[i].memory, data[i].screen, data[i].price);
        i++;
    }

    // free memory and close file
    free(data);
    fclose(fin);

}

void printDB(int size, char filename[]){
    FILE *fin;
    phoneInfo *data;
    int n, irc, i=0;

    // open file
    if ((fin = fopen(filename, "rb")) == NULL){
        printf("Cannot open %s.\n", filename);
        return;
    }

    // allocate memory
    data = (phoneInfo *) malloc(size * sizeof(phoneInfo));
    if (data == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    // Read data
    irc = fread(data, sizeof(phoneInfo), size, fin);

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    getchar();
    while (i < irc){
        if (i % 10 == 0 && i != 0){
            printf("- page %d -\n", i/10);
            printf("Press Enter to go to next page");
            getchar();
            printf("\e[1;1H\e[2J");
            printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
        }
        printf(" %-3d %-25s %6d %13.2f %16d\n", i+1, data[i].name, data[i].memory, data[i].screen, data[i].price);
        i++;
    }

    // free memory and close file
    free(data);
    fclose(fin);
}

void search(int size, char filename[]){
    FILE *fin;
    phoneInfo *data;
    char s[30];
    int n, irc, i=0;

    // open file
    if ((fin = fopen(filename, "rb")) == NULL){
        printf("Cannot open %s.\n", filename);
        return;
    }

    // allocate memory
    data = (phoneInfo *) malloc(size * sizeof(phoneInfo));
    if (data == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    // Read data
    irc = fread(data, sizeof(phoneInfo), size, fin);

    // get search string
    printf("Search phone: "); scanf("%s", s);

    printf("\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    getchar();
    while (i < irc){
        if (strstr(data[i].name, s) != NULL){
            printf(" %-3d %-25s %6d %13.2f %16d\n", i+1, data[i].name, data[i].memory, data[i].screen, data[i].price);
        }
        i++;
    }

    // free memory and close file
    free(data);
    fclose(fin);
}

int main(){
    int reval = SUCCESS;
    int tmp, size = 0;
    int user_choice;
    char filetxt[] = "phoneDB.txt",
         filedat[] = "phoneDB.dat";

    do {
        // print menu
        printf("\e[1;1H\e[2J");
        printf("\n\t\t *** Phone Catalog program ***\n\n");

        printf("1. Import Database from text\n");
        printf("2. Import from Database\n");
        printf("3. Print all Database\n");
        printf("4. Search by phone by Phone Model\n");
        printf("5. Exit");

        // Get user choice
        printf("\n=> Your choice: "); scanf("%d", &user_choice);

        switch(user_choice){
            case 1:
                printf("\e[1;1H\e[2J");
                tmp = importDB(filetxt, filedat);
                if (tmp > 0)
                    size = tmp;
                break;
            case 2:
                printf("\e[1;1H\e[2J");
                printf("Import from Database:\n");
                printf("- Full reading mode (F) / Read from the beginning (B) / Read from the end (E)? ");
                readDB(size, filedat);
                break;
            case 3:
                printf("\e[1;1H\e[2J");
                printDB(size, filedat);
                break;
            case 4:
                printf("\e[1;1H\e[2J");
                search(size, filedat);
                break;
            case 5:
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
        if (user_choice != 5){
            printf("Press Enter to continue...\n");
            getchar(); getchar();
        }
    } while (user_choice != 5);

    return reval;
}
