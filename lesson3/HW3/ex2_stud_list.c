#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define WORD_LEN 30
#define ID_LEN 8
#define PHONE_LEN 10

typedef struct
{
    int no;
    char id[ID_LEN+1];
    char name[WORD_LEN];
    char phone_num[PHONE_LEN+1];
    float score;
} student;

int main()
{
    FILE *fin, *fout;
    char fin_name[] = "input2.txt",
         fout_name[] = "bangdiem.txt";
    student stu_list[MAX];
    int i=0;

    if ((fin = fopen(fin_name, "r")) == NULL)
    {
        printf("Cannot open file %s!\n", fin_name);
    } else if ((fout = fopen(fout_name, "w")) == NULL){
        printf("Cannot open file %s!\n", fout_name);
    } else {
        fprintf(fout, "%-3s\t%8s\t%-30s\t%10s\t%5s\n", "No", "StudentID", "Name", "Phone number", "Score");

        // Get student's scores from input
        printf("Enter score for each student:\n");
        while (fscanf(fin, "%d %s %s %s", &stu_list[i].no, stu_list[i].id, stu_list[i].name, stu_list[i].phone_num) != EOF){
            printf("ID: %s -> Score: ", stu_list[i].id);
            scanf("%f", &stu_list[i].score);
            fprintf(fout, "%-3d\t%8s\t%-30s\t%10s\t%-5.2f\n", stu_list[i].no, stu_list[i].id, stu_list[i].name, stu_list[i].phone_num, stu_list[i].score);
            i++;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
