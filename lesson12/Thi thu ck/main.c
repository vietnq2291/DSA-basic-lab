#include<stdio.h>
#include<string.h>
#include"./lib/tree.h"
#define MAX 1000

Node *root = NULL;

void read_file(char filename[], Node *root) {
    FILE *fptr;
    ElementType e;
    char print_sorted;
    ElementType *data;

    // open file
    if ((fptr = fopen(filename, "r")) == NULL){
        printf("Cannot open %s.\n", filename);
        return;
    }

    // ask user if they want to print sorted
    printf("Press any key to print sorted or Enter to print normally: ");
    print_sorted = getchar();    
    if (print_sorted != '\n') getchar();

    // read data
    while (feof(fptr) == 0) {
        e = read_data(fptr);
        root = insert_node(root, e);
        if (print_sorted == '\n') {
            print_data(e);
        }
    }

    if (print_sorted != '\n') {
        print_tree(root);
    }

    // Close file
    free(data);
    fclose(fptr);
}

void showMenu() {
    printf("\e[1;1H\e[2J");
    printf("\n\t\t *** MAP v1.0 ***\n\n");

    // printf("Status:\n");
    // printf("- Current pointer: ");
    // if (cur != NULL) print_data(cur->element, stdout);
    // else printf("%p\n", cur);

    printf("\nOptions:\n");
    printf("1. Load path\n");
    printf("2. Load checkpoint\n");
    printf("3. Manually add path/checkpoint\n");
    printf("4. Routing\n");
    printf("5. Quit");

}

int main(){

    int ch;
    int user_choice;
    char path_file[] = "data/path.txt",
         checkpoint_file[] = "data/checkpoint.txt";

    do {
        // print menu
        showMenu();        

        // Get user choice
        printf("\n=> Your choice: "); 
        scanf("%d", &user_choice); while((ch = getchar()) != '\n');

        // printf("\e[1;1H\e[2J");
        switch(user_choice){
            case 1:
                read_file(path_file, root);
                break;
            case 2:
                print_tree(root);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Closing the program...\n");
                // free_list(&root, &tail, &cur);
                break;
            default:
                printf("Invalid choice!!\n");
        }
        if (user_choice != 5){
            printf("Press Enter to continue...\n");
            getchar();
        }
    } while (user_choice != 5);

    

    // while(1){
    //     char cmd[256];
    //     printf("Enter command: ");
    //     scanf("%s",cmd); getchar();
    //     if(strcmp(cmd,"Quit") == 0) break;
    //     // else if(strcmp(cmd,"Load")==0) processLoad();
    //     else if(strcmp(cmd,"Print")==0) process_print(root);
    //     else if(strcmp(cmd,"Find")==0) process_find(root);
    //     else if(strcmp(cmd,"FindChildren")==0) process_find_children(root);
    //     else if(strcmp(cmd,"Height")==0) process_height(root);
    //     // else if(strcmp(cmd,"Count")==0) processCount(); //--
    //     else if(strcmp(cmd,"AddChild")==0) process_add_child(root);
    //     else if(strcmp(cmd,"AddSibling")==0) process_add_sibling(root);
    //     // else if(strcmp(cmd,"Store")==0) processStore(); //--
    // }
    // freeTree(root); //--

    return 0;
}
