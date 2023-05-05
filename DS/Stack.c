#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;
typedef struct Stack{
    Node *top;
    int count;
}Stack;

void initStack(Stack *stack);
int isEmpty(Stack *stack);
int Push(Stack *stack, int data);
int Pop(Stack *stack);

int main(){
    int i;
    Stack stack;
    initStack(&stack);
    for (i=1;i<=10;i++){
        Push(&stack,i);
    }
    while (!isEmpty(&stack)){
        printf("%d ",Pop(&stack));
    }
    printf("\n");
    return 0;
}

void initStack(Stack *stack){
    stack->top = NULL;
    stack->count = 0;
}
int isEmpty(Stack *stack){
    return stack->count == 0;
}
int Push(Stack *stack, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = stack->top;
    stack->top = newNode;
    stack->count++;
}
int Pop(Stack *stack){
    int data;
    Node *ptr;
    if(isEmpty(stack)){
        printf("Error : Stack is empty\n");
        return 0;
    }
    ptr = stack->top;
    data = ptr->data;
    stack->top = ptr->prev;
    free(ptr);
    stack->count--;
    return data;
}
