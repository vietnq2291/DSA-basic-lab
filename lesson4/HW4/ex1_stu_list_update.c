#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 100

typedef struct student_t{
    int no;
    char id[9];
    char name[30];
    char phone_num[11];
    float score;
} student;

int main()
{
    FILE *fin, *fout;
    char fin_name[] = "student_list.txt",
         fout_name[] = "transcript.txt";
    student *stu_list;
    int n, i=0;

    if ((fin = fopen(fin_name, "rb")) == NULL)
    {
        printf("Cannot open file %s!\n", fin_name);
    } else if ((fout = fopen(fout_name, "wb")) == NULL){
        printf("Cannot open file %s!\n", fout_name);
    } else {
        // allocate memory for student list
        stu_list = (student *) malloc(10 * sizeof(student));
        if (stu_list == NULL){
            printf("Memory allocation failed!\n");
            return 1;
        }

        // print title into output file
        fprintf(fout, "%-3s\t%8s\t%-30s\t%10s\t%5s\n", "No", "StudentID", "Name", "Phone number", "Score");

        // get student scores from input, then write into output file
        printf("Enter score for each student:\n");
        while (fscanf(fin, "%d,%[^,],%[^,],%s", &stu_list[i].no, stu_list[i].id, stu_list[i].name, stu_list[i].phone_num) != EOF){
            printf("ID: %s -> Score: ", stu_list[i].id);
            scanf("%f", &stu_list[i].score);
            fprintf(fout, "%-3d\t%8s\t%-30s\t%10s\t%-5.2f\n", stu_list[i].no, stu_list[i].id, stu_list[i].name, stu_list[i].phone_num, stu_list[i].score);
            i++;
        }

        // add students
        char user_choice;
        printf("Input more (Y/N)? ");
        scanf(" %c", &user_choice);
        if (user_choice == 'y' || user_choice == 'Y'){
            printf("Number of new students: ");
            scanf("%d", &n);

            // reallocate memory location
            stu_list = realloc(stu_list, (n + i) * sizeof(student));
            if (stu_list == NULL){
                printf("Reallocate memory failed!\n");
            }

            // Get new student data
            for (int j = i; j < (n+i); j++){
                printf("Student #%d:\n", j - i + 1);
                stu_list[j].no = j + 1;

                printf("- Student id: ");
                scanf(" %s", stu_list[j].id);

                printf("- Student name: ");
                scanf(" %[^\n]", stu_list[j].name);

                printf("- Student phone number: ");
                scanf("%s", stu_list[j].phone_num);

                printf("- Student score: ");
                scanf("%f", &stu_list[j].score);

                fprintf(fout, "%-3d\t%8s\t%-30s\t%10s\t%-5.2f\n", stu_list[j].no, stu_list[j].id, stu_list[j].name, stu_list[j].phone_num, stu_list[j].score);
            }
        }

        free(stu_list);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
