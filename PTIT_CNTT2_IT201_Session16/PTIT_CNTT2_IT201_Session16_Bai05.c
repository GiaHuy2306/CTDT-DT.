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

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int* isEmpty (Queue* q) {
    return (q->front == NULL);
}

void equeue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong khong the lay phan tu");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;;
    free(temp);
}

int getFront(Queue* q) {
    if (isEmpty(q)) {
        printf("is empty queue");
        return -1;
    }
    return q->front->data;
}

void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Hang doi hien tai: \n");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();
    int value;
    equeue(myQueue, 10);
    equeue(myQueue, 20);
    equeue(myQueue, 30);
    printQueue(myQueue);
    printf("Nhap phan tu muon them: ");
    scanf("%d", &value);
    equeue(myQueue, value);
    printQueue(myQueue);

    int x = getFront(myQueue);
    if (x != -1) {
        printf("%d\n", x);
    }
    dequeue(myQueue);
    printQueue(myQueue);
    return 0;
}