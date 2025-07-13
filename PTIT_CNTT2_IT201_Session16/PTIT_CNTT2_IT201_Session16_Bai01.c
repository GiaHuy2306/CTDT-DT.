#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue () {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int main () {
    Queue* myQueue = createQueue();
    if (myQueue->front == NULL && myQueue->rear == NULL) {
        printf("Hang doi da duoc khoi tao va dang rong");
    }
    return 0;
}