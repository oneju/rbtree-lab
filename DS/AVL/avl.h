#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *SearchNode(Node *tree, int data);
int NodeHeight(Node *node);
int BF(Node *node);

Node *LL(Node *node);
Node *RR(Node *node);
Node *LR(Node *node);
Node *RL(Node *node);

Node *AVL(Node *node);
Node *Insert(Node *node, int data);
void Delete(Node *node, int data);

void InorderPrint(Node *tree);