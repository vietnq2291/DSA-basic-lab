#include<stdio.h>
#include<string.h>
#include"tree.h"

Node *root = NULL;

void read_inputfile(char filetxt[], Node *root) {
    FILE *fptr;
    ElementType lane, cnt_lane;
    Node *found_lane;
    char c;

    // open file
    if ((fptr = fopen(filetxt, "r")) == NULL){
        printf("Cannot open %s.\n", filetxt);
        return;
    }

    // read lane node
    while (c != EOF) {
        lane = read_data(fptr, root);

        if ((found_lane = find(root, lane)) == NULL) {
            add_child(root->element, lane, root);
        } else {
            found_lane->element = lane;
        }

        // connected lane
        do {
            fscanf(fptr, "%s", cnt_lane.name);
            cnt_lane.length = 0;
            add_child(lane, cnt_lane, root);
            c = fgetc(fptr);
        } while (c != '\n' && c != EOF);
    }

    printf("\nData imported successfully!\n");

    // Close file
    fclose(fptr);
}

int print_intersections(Node *r) {
    if (r == NULL) return 0;

    // print children
    Node *p = r->left_most_child;
    while (p != NULL) {
        print_data(p->element);
        p = p->right_sibling;
    }
    printf("\n");

    // continue print all levels of tree
    p = r->left_most_child;
    while (p != NULL) {
        print_tree(p);
        p = p->right_sibling;
    }
}

void showMenu() {
    printf("\e[1;1H\e[2J");
    printf("\n\t\t =======CHOOSE THE FUNCTION======= \n\n");

    printf("\nOptions:\n");
    printf("A for “Print all intersections”\n");
    printf("B for “Print degree of an intersection”\n");
    printf("C for “Print all lanes that connect directly to an intersection”\n");
    printf("D for “Print waiting time and lane”\n");
    printf("E for “Upgrade the D function”\n");
    printf("F for QUIT\n");

}

int main(){
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

    int ch;
    char user_choice;
    char input_txt[] = "input2.txt",
         carlog_txt[] = "carlog.txt";

    // Create root node
    ElementType root_lane;
    strcpy(root_lane.name, "root");
    root = add_last(root, root_lane);

    // read file
    read_inputfile(input_txt, root);
    printf("print tree:\n");
    print_tree(root);

    do {
        // print menu
        showMenu();        

        // Get user choice
        printf("\n=> Your choice: "); 
        scanf("%c", &user_choice); while((ch = getchar()) != '\n');

        printf("\e[1;1H\e[2J");
        switch(user_choice){
            case 'A': case 'a':
                print_intersections(root);
                break;
            case 'B': case 'b':
                printf("b\n");
                break;
            case 'C': case 'c':
                printf("c\n");
                break;
            case 'D': case 'd':
                printf("D\n");
                break;
            case 'E': case 'e':
                printf("E\n");
                break;
            case 'F': case 'f':
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
        if (user_choice != 'F' && user_choice != 'f'){
            printf("Press Enter to continue...\n");
            getchar();
        }
    } while (user_choice != 'f' && user_choice != 'F');


    return 0;
}
