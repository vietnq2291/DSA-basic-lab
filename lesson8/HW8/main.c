#include<stdio.h>
#include<stdlib.h>
#include"GenSLL.h"

#define MAX_ELEMENT 100

SingleList root, cur, prev;


void importDB(char filedat[], SingleList *root, SingleList *cur, SingleList *prev) {
    FILE *fptr;
    ElementType *data;
    int irc;

    // open file
    if ((fptr = fopen(filedat, "rb")) == NULL){
        printf("Cannot open %s.\n", filedat);
        return;
    }

    // allocate memory
    data = (ElementType *) malloc(MAX_ELEMENT * sizeof(ElementType));

    // read data
    irc = fread(data, sizeof(ElementType), MAX_ELEMENT, fptr);
    for (int i = 0; i < irc; i++) {
        insert_after_current(data[i], root, cur, prev);
    }

    printf("\nDatabase imported successfully!\n");

    // Free memory and close files
    free(data);
    fclose(fptr);
}

void add_new_phone(SingleList *root, SingleList *cur, SingleList *prev) {
    int choice;

    ElementType phone = read_data();

    printf("\nOptions:\n");
    printf("1. Insert before current position\n");
    printf("2. Insert after current position\n");
    printf("0. return\n");

    printf("\n=> Your choice: "); scanf("%d", &choice);
    switch(choice) {
        case 0:
            return;
        case 1:
            insert_before_current(phone, root, cur, prev);
            break;
        case 2:
            insert_after_current(phone, root, cur, prev);
            break;
        default:
            printf("Invalid choice!");
            return;
    }

    printf("\nPhone added successfully!\n");
}

void insert_new_phone(SingleList *root, SingleList *cur, SingleList *prev) {
    int n;

    ElementType phone = read_data();

    printf("\nOptions:\n");
    printf("Position to insert new phone: "); scanf("%d", &n);
    Node *new = insert_at_position(phone, n, root, cur, prev);

    if (new != NULL) printf("\nPhone added successfully!\n");
    else printf("Failed addding new phone!\n");
}

void search_and_update(SingleList *root, SingleList *cur, SingleList *prev){
    char s[20];
    Node *p;
    // get search string
    printf("Search phone: "); scanf("%[^\n]", s);
    getchar();

    p = search(s, root, cur, prev);
    if (p != NULL) (*cur) = p;
    else return;

    // update
    ElementType phone = read_data();
    (*cur)->element = phone;
}

void save_to_file(char filetxt[], Node *data) {
    Node *p;
    int i=0;
    FILE *fptr;

    // open file
    if ((fptr = fopen(filetxt, "w")) == NULL){
        printf("Cannot open %s.\n", filetxt);
        return;
    }
    

    fprintf(fptr, "\n %3s    %-21s %11s %13s %9s\n", "No.", "Model", "Memory (GB)", "Screen (inch)", "Price");
    for (p = data; p != NULL; p = p->next, i++){
        fprintf(fptr, " %-3d ", i);
        print_data(p->element, fptr);
    }
    printf("\n");
    fclose(fptr);
}

void split_list(char sublist1[], char sublist2[], SingleList *root) {
    int n1, n2;
    printf("Splitting list:\n");

    printf("- Index to split: "); scanf("%d", &n1);
    printf("- Number of elements: "); scanf("%d", &n2);

    Node *sublist = split(root, n1, n2);
    save_to_file(sublist1, sublist);
    save_to_file(sublist2, *root);
    
    getchar();
}


void showMenu() {
    printf("\e[1;1H\e[2J");
    printf("\n\t\t *** Phone Catalog program v2.0 ***\n\n");

    printf("Status:\n");
    printf("- Current pointer: ");
    if (cur != NULL) print_data(cur->element, stdout);
    else printf("%p\n", cur);

    printf("\nOptions:\n");
    printf("1. Import from PhoneDB.dat\n");
    printf("2. Display\n");
    printf("3. Add new phone\n");
    printf("4. Insert at Position\n");
    printf("5. Delete at Position\n");
    printf("6. Delete current\n");
    printf("7. Delete first\n");
    printf("8. Search and Update\n");
    printf("9. Divide and Extract\n");
    printf("10. Reverse List\n");
    printf("11. Save to File\n");
    printf("12. Quit");

}

int main() {
    int ch, n;
    int user_choice;
    Node *temp;
    char filetxt[] = "phoneDB.txt",
         filedat[] = "phoneDB.dat",
         sublist1[] = "sublist1.txt",
         sublist2[] = "sublist2.txt";

    do {
        // print menu
        showMenu();        

        // Get user choice
        printf("\n=> Your choice: "); 
        scanf("%d", &user_choice); while((ch = getchar()) != '\n');

        printf("\e[1;1H\e[2J");
        switch(user_choice){
            case 1:
                importDB(filedat, &root, &cur, &prev);
                break;
            case 2:
                traverse_list(root);
                break;
            case 3:
                add_new_phone(&root, &cur, &prev);
                break;
            case 4:
                insert_new_phone(&root, &cur, &prev);
                break;
            case 5:
                printf("Phone position to delete: "); scanf("%d", &n);
                delete_at_position(n, &root);
                break;
            case 6:
                delete_element(cur->element, &root);
                break;
            case 7:
                delete_at_position(0, &root);
                break;
            case 8:
                search_and_update(&root, &cur, &prev);
                break;
            case 9:
                split_list(sublist1, sublist2, &root);
                break;
            case 10:
                root = list_reverse(&root);
                break;
            case 11:
                save_to_file(filetxt, root);
                break;
            case 12:
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
        if (user_choice != 12){
            printf("Press Enter to continue...\n");
            getchar();
        }
    } while (user_choice != 12);

    return 0;
}