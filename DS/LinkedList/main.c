#include "header.h"

int main(){
    List *list = (List *)malloc(sizeof(List));
    initList(list);
    
    printf("+1\n");
    insertFirstNode(list, 1);

    printf("+3\n");
    insertLastNode(list, 3);

    printf("+2\n");
    insertFirstNode(list, 2);

    printf("+4\n");
    insertMidNode(list, 4, 1);

    printf("-1\n");
    deleteNode(list,1);

    printList(list);
    freeLinkedList(list);
    return 0;
}