#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t *nil = (node_t *)calloc(1, sizeof(node_t));
  nil->color = RBTREE_BLACK;
  p->root = nil;
  p->nil = nil;
  node_t *nil = (node_t *)calloc(1, sizeof(node_t));
  nil->color = RBTREE_BLACK;
  p->root = nil;
  p->nil = nil;
  return p;
}

void tree_free(rbtree *t,node_t *d){
  if (d != t->nil){
    tree_free(t,d->left);
    tree_free(t,d->right);
    free(d);
  }
}
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  tree_free(t,t->root);
  free(t->nil);
  free(t);
}

void LeftRotation(rbtree *t,node_t *x){
  node_t *y = x->right;
  x->right = y->left;
  if (y->left != t->nil){y->left->parent = x;}
  y->parent = x->parent;
  if (x->parent==t->nil){t->root = y;}
  else if (x->parent->left==x){x->parent->left = y;}
  else {x->parent->right = y;}
  x->parent = y;
  y->left = x;
}

void RightRotation(rbtree *t,node_t *x){
  node_t *y = x->left;
  x->left = y->right;
  if (y->right != t->nil){y->right->parent = x;}
  y->parent = x->parent;
  if (x->parent==t->nil){t->root = y;}
  else if (x->parent->right==x){x->parent->right = y;}
  else {x->parent->left = y;}
  x->parent = y;
  y->right = x;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node_t *p, *h = t->nil;
  node->key = key;
  node->color = RBTREE_RED;
  node->left = node->right = node->parent = t->nil;
  // find
  p = t->root;
  while (p!=t->nil){
    h = p;
    if (p->key > key){
      p = p->left;
    }else{
      p = p->right;
    }
  }
  // insertion
  if (h == t->nil) t->root = node;
  else if (h->key > key) h->left = node;
  else h->right = node;
  
  node->parent = h;
  // fixup
  while (node->parent->color == RBTREE_RED){
    if (node->parent == node->parent->parent->left){
      // p == parent->left
      // case 1
      if (node->parent->parent->right->color == RBTREE_RED){
        node->parent->parent->color = RBTREE_RED;
        node->parent->color = node->parent->parent->right->color = RBTREE_BLACK;
        node = node->parent->parent;
      }
      else {
        // case 2
        if(node->parent->right == node){
          // Left Rotation
          node=node->parent;
          LeftRotation(t,node);
        }// case 3
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        RightRotation(t,node->parent->parent);
      }
    }
    else{
      // p == parent->right
      // case 1
      if (node->parent->parent->left->color == RBTREE_RED){
        node->parent->parent->color = RBTREE_RED;
        node->parent->color = node->parent->parent->left->color = RBTREE_BLACK;
        node = node->parent->parent;
      }
      else {
        // case 2
        if(node->parent->left == node){
          // Right Rotation
          node=node->parent;
          RightRotation(t,node);
        }// case 3
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        LeftRotation(t,node->parent->parent);
      }
    } 
  }
  t->root->color = RBTREE_BLACK;
  return node;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t *p = t->root;
  while (p){
    if (p->key == key) return p;
    if (p->key > key){
      p = p->left;
    }else{
      p = p->right;
    }
  }
  return NULL;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t *p = t->root;
  while (p->left != t->nil) p=p->left;
  return p;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t *p = t->root;
  while (p->right != t->nil) p=p->right;
  return p;
}

void transplant(rbtree *t,node_t *u,node_t *v){
  if (u->parent == t->nil){ t->root = v;}
  else if (u==u->parent->left){ u->parent->left = v;}
  else{ u->parent->right = v;}
  v->parent = u->parent;
}
int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  node_t *node = p;
  node_t *x = t->nil, *w = t->nil;
  color_t originalcolor = node->color;
  if (p->left == t->nil){
    x = p->right;
    transplant(t,p,p->right);
  }else if(p->right==t->nil){
    x = p->left;
    transplant(t,p,p->left);
  }else{
    // p의 자식이 둘일 때
    node = node->right;
    while(node->left!=t->nil){node = node->left;}
    originalcolor = node->color;
    x = node->right;
    if (node->parent == p){
      x->parent = node;
    }else{
      transplant(t,node,node->right);
      node->right = p->right;
      node->right->parent = node;
    }
    transplant(t,p,node);
    node->left = p->left;
    node->left->parent = node;
    node->color = p->color;
  }
  if (originalcolor == RBTREE_BLACK){
    // fixup
    while (x!=t->root && x->color == RBTREE_BLACK){
      if (x==x->parent->left){
        w=x->parent->right;
        if (w->color == RBTREE_RED){
          w->color = RBTREE_BLACK;
          x->parent->color = RBTREE_RED;
          LeftRotation(t,x->parent);
          w = x->parent->right;
        }
        if (w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK){
          w->color = RBTREE_RED;
          x=x->parent;
        }else {
          if(w->right->color == RBTREE_BLACK){
            w->left->color = RBTREE_BLACK;
            w->color = RBTREE_RED;
            RightRotation(t,w);
            w = x->parent->right;
          }
          w->color = x->parent->color;
          x->parent->color = RBTREE_BLACK;
          w->right->color = RBTREE_BLACK;
          LeftRotation(t,x->parent);
          x = t->root;
        }
      }else{
        w=x->parent->left;
        if (w->color == RBTREE_RED){
          w->color = RBTREE_BLACK;
          x->parent->color = RBTREE_RED;
          RightRotation(t,x->parent);
          w = x->parent->left;
        }
        if (w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK){
          w->color = RBTREE_RED;
          x=x->parent;
        }else {
          if(w->left->color == RBTREE_BLACK){
            w->right->color = RBTREE_BLACK;
            w->color = RBTREE_RED;
            LeftRotation(t,w);
            w = x->parent->left;
          }
          w->color = x->parent->color;
          x->parent->color = RBTREE_BLACK;
          w->left->color = RBTREE_BLACK;
          RightRotation(t,x->parent);
          x = t->root;
        }
      }
    }
  }
  x->color = RBTREE_BLACK;
  return 0;
}
// Tree to In-order Array
int Inorder(const rbtree *t, node_t *node, key_t *arr, const size_t n, int idx){
  if (idx < n){
    if (node->left != t->nil){
      idx = Inorder(t,node->left,arr,n,idx);
    }
    arr[idx++] = node->key;
    if (node->right != t->nil){
      idx = Inorder(t,node->right,arr,n,idx);
    }
  }
  return idx;
}
int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  Inorder(t,t->root,arr,n,0);
  return 0;
}
