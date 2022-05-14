#include<stdio.h>

int main(){
    struct list{
        char data;
        struct list *link;
    } item1, item2, item3;
    item1.data = 'a';
    item2.data = 'b';
    item3.data = 'c';
    item1.link = &item2;
    item2.link = &item3;
    item3.link = NULL;
    printf("%p %p %p\n", item1.link, item2.link, item3.link);
    return 0;
}
