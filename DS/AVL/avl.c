#include "avl.h"

int NodeHeight(Node *node){
    if (node == NULL) return 0;
	
    int leftDepth = NodeHeight(node->left);
    int rightDepth = NodeHeight(node->right);
	
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int BF(Node *node){
    if (node == NULL){return 0;}
    return NodeHeight(node->left)-NodeHeight(node->right);
}

// Rotations
Node *LL(Node *node){
    Node *LNode = node->left;
    node->left = LNode->right;
    LNode->right = node;
    return LNode;
}

Node *RR(Node *node){
    Node *RNode = node->right;
    node->right = RNode->left;
    RNode->left = node;
    return RNode;
}

Node *LR(Node *node){
    Node *Left = node->left;
    Left = RR(Left);
    return LL(node);
}

Node *RL(Node *node){
    Node *Right = node->right;
    Right = LL(Right);
    return RR(node);
}

// Re-Balance
Node *AVL(Node *node){
    int bf = BF(node);
    if (bf > 1){
        if (BF(node->left)>0){
            node = LL(node); 
        }else{
            node = LR(node);
        }
    }else if (bf < -1){
        if (BF(node->right)<0){
            node = RR(node);
        }else{
            node = RL(node);
        }
    }
    return node;
}

Node *Insert(Node *node, int data){
    if (!node){
        node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data < node->data){
        node->left = Insert(node->left,data);
        node = AVL(node);
    }else if (data > node->data){
        node->right = Insert(node->right,data);
        node = AVL(node);
    }else{
        printf("Already Exist : %d\n",data);
    }
    return node;
}

void Delete(Node *node, int data){
    while (node){
        if (node->data > data){
            if (node->left->data == data){break;}
            else{node = node->left;}
        }else if (node->data < data){
            if (node->right->data == data){break;}
            else{node = node->right;}
        }
    }
    if (!node) {printf("no data\n");}
    else{
        if (node->left->data == data){
            if (node->left->left){node->left = node->left->left;}
            else if(node->left->right){node->left = node->left->right;}
            else {node->left = NULL;}
        }else{
            if (node->right->left){node->right = node->right->left;}
            else if(node->right->right){node->right = node->right->right;}
            else {node->right = NULL;}
        }
        AVL(node);
    }
}

void InorderPrint(Node *node){
    if (!node) return;
	
    InorderPrint(node->left);
    printf("%d ", node->data);
    InorderPrint(node->right);
}