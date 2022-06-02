#include<stdio.h>
#include<string.h>
#include"tree.h"

Node *root = NULL;

int main(){
    ElementType e = read_data();
    root = add_last(root, e);

    while(1){
        char cmd[256];
        printf("Enter command: ");
        scanf("%s",cmd); getchar();
        if(strcmp(cmd,"Quit") == 0) break;
        // else if(strcmp(cmd,"Load")==0) processLoad();
        else if(strcmp(cmd,"Print")==0) process_print(root);
        else if(strcmp(cmd,"Find")==0) process_find(root);
        else if(strcmp(cmd,"FindChildren")==0) process_find_children(root);
        else if(strcmp(cmd,"Height")==0) process_height(root);
        // else if(strcmp(cmd,"Count")==0) processCount(); //--
        else if(strcmp(cmd,"AddChild")==0) process_add_child(root);
        else if(strcmp(cmd,"AddSibling")==0) process_add_sibling(root);
        // else if(strcmp(cmd,"Store")==0) processStore(); //--
    }
    // freeTree(root); //--

    return 0;
}
