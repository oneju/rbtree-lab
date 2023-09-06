#include "header.h"

void freeLinkedList(List *h){
    Node *n;
    while (h->head != NULL) {
        n = h->head;
        h->head = h->head->next;
        free(n);
        n = NULL;
    }
}

void initList(List *h){
    h->head = NULL;
    
}
void insertFirstNode(List *h, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = h->head;
    h->head = newNode;
}
void insertMidNode(List *h, int data, int prev){
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *ptr;
    int find = 0;
    newNode->data = data;
    ptr = h->head;
    while (ptr->next != NULL)
    {
        if (ptr->data==prev)
        {
            find = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (find==1){
        newNode->next = ptr->next;
        ptr->next = newNode;
    }else{
        printf("No data : %d",prev);
    }
}
void insertLastNode(List *h, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *ptr = h->head;
    while(ptr->next){
        ptr=ptr->next;
    }
    ptr->next = newNode;
}
void deleteNode(List *h,int data){
    Node *ptr = h->head;
    int find = 0;
    while(ptr->next){
        if(ptr->next->data == data){
            find = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (find==0){
        printf("No data : %d",data);
    }else{
        ptr->next = ptr->next->next;
    }
}
void printList(List *h){
    Node *ptr = h->head;
    
    printf("=====PRINT LIST=====\n");
    while(ptr){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
