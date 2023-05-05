#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct Queue{
    Node *front;
    Node *rear;
    int count;
}Queue;

void initQueue(Queue *queue);
int isEmpty(Queue *queue);
int Enqueue(Queue *queue, int data);
int Dequeue(Queue *queue);

int main(){
    int i;
    Queue queue;
    initQueue(&queue);
    for (i=1;i<=10;i++){
        Enqueue(&queue,i);
    }
    while(!isEmpty(&queue)){
        printf("%d ",Dequeue(&queue));
    }
    printf("\n");
    return 0;
}

void initQueue(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
}
int isEmpty(Queue *queue){
    return queue->count == 0; // queue count가 0이면 빈 상태
}
int Enqueue(Queue *queue, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)){
        queue->front = newNode;
    }else{
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
}
int Dequeue(Queue *queue){
    int data;
    Node *ptr;
    if(isEmpty(queue)){
        printf("Error : Queue is empty\n");
        return 0;
    }
    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;

    return data;
}