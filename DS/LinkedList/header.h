#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct List{
    Node *head;
}List;
void freeLinkedList(List *h);
void initList(List *h);
void insertFirstNode(List *h, int data);
void insertMidNode(List *h, int data, int prev);
void insertLastNode(List *h, int data);
void deleteNode(List *h,int data);
void printList(List *h);