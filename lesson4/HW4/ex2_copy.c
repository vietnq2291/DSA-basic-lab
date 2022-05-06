#include<stdio.h>
#include<time.h>
#include<unistd.h>
enum {SUCCESS, FAIL, MAX_LEN = 80};

void copy_by_char(FILE *fin, FILE *fout){
    char c;
    clock_t begin = clock();

    while ((c = fgetc(fin)) != EOF){
        fputc(c, fout);
    }

    clock_t end = clock();

    printf(" Execution time of copying by character: %lf\n", (double)(end - begin)/CLOCKS_PER_SEC);
}

void copy_by_line(FILE *fin, FILE *fout){
    char buff[MAX_LEN];
    clock_t begin = clock();

    while (fgets(buff, MAX_LEN, fin) != NULL){
        fputs(buff, fout);
    }

    clock_t end = clock();

    printf(" Execution time of copying by line: %lf\n", (double) (end - begin)/CLOCKS_PER_SEC);

}

void copy_by_block(FILE *fin, FILE *fout){
    char buff[MAX_LEN];
    int count;

    clock_t begin = clock();

    while ((count = fread(buff, sizeof(char), MAX_LEN, fin)) >= 1){
        buff[count * sizeof(char)] = '\0';
        fwrite(buff, sizeof(char), count * sizeof(char), fout);
    }

    clock_t end = clock();

    printf("Execution time of copying by block: %lf\n", (double) (end - begin)/CLOCKS_PER_SEC);
}


int main(){
    char user_choice;
    FILE *fin, *fout;
    char fin_name[] = "ex2_data.txt",
         fout_name[] = "ex2_data_copied.txt";
    int reval = SUCCESS;

    // Open files
    if ((fin = fopen(fin_name, "rb")) == NULL){
        printf("Cannot open %s.\n", fin_name);
        reval = FAIL;
    } else if ((fout = fopen(fout_name, "wb")) ==  NULL){
        printf("Cannot open %s.\n", fout_name);
        reval = FAIL;
    } else {

        // Main menu
        do {
            // print menu interface
            printf("\n\t\t*** Multi-modes copy program ***\n\n");
            printf("1. Copy by character\n");
            printf("2. Copy by line\n");
            printf("3. Copy by block - optional size\n");
            printf("Or enter (Q) to quit.\n");

            printf("\n=> Your choice: ");
            scanf(" %c", &user_choice);

            switch (user_choice){
                case '1':
                    copy_by_char(fin, fout);
                    break;
                case '2':
                    copy_by_line(fin, fout);
                    break;
                case '3':
                    copy_by_block(fin, fout);
                    break;
                case 'q': case 'Q':
                    printf("Closing program ...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }

            // Move cursor to the beginning of files
            rewind(fin);
            rewind(fout);
        } while (user_choice != 'q' && user_choice != 'Q');
    }

    return reval;
}
