#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_LEN 100

void decode_text(FILE *fin, FILE *fout, int off_set){
    char c, base;

    while ((c = fgetc(fin)) != EOF){
        if (isalpha(c)){
            if (isupper(c))
                base = 'Z';
            else if (islower(c))
                base = 'z';
            c = base - (base - c + off_set) % 26;
        }
        fputc(c, fout);
    }
}


int main(int argc, char *argv[]){
    FILE *fin, *fout;
    char fout_name[] = "decoded1.txt";

    if (argc != 3){
        printf("Wrong number of argument!\n");
        printf("Correct syntax is: caesar_cipher <file_name> <off_set>\n");
    } else {
        // Open files
        if ((fin = fopen(argv[1], "r")) == NULL){
            printf("Cannot open file %s!\n", argv[1]);
            return 1;
        } else if ((fout = fopen(fout_name, "w")) == NULL){
            printf("Cannot open file %s to write!\n", fout_name);
            return 1;
        }

        // Decode text
        printf("Decoding in progress...\n");
        sleep(3);
        decode_text(fin, fout, atoi(argv[2]));
        printf("Decoded successfully! Result is stored in %s\n", fout_name);

    }

    return 0;
}
