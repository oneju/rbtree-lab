#include "rbtree.h"
#include "rbtree.c"
#include <stdio.h>
#include "rbtree.c"
#include <stdio.h>

int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();

    rbtree_insert(t, 8);
    rbtree_insert(t, 7);
    rbtree_insert(t, 9);
    rbtree_insert(t, 3);
    rbtree_insert(t, 6);
    rbtree_insert(t, 4);
    rbtree_insert(t, 5);
    rbtree_insert(t, 12);

    printf("%d\n",t->root->key);
    printf("%d\n",t->root->color);
    printf("%d\n",t->root->left->left->right->key);
    printf("%d\n",t->root->left->left->right->color);
    printf("최소%d\n", rbtree_min(t)->key);
    printf("최대%d\n",rbtree_max(t)->key);

}