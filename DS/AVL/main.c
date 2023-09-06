#include "avl.h"
int main()
{
    Node *root = NULL;
    //INSERT
    root = Insert(root, 4);
    root = Insert(root, 10);
    root = Insert(root, 13);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 32);
    root = Insert(root, 55);
    
    InorderPrint(root);
    printf("\n");
    Delete(root,10);
    InorderPrint(root);

    return printf("\n");
    //결과 : 4 10 13 20 25 32 55
    
}