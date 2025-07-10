#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int maxSize;
}Queue;

Queue createQueue(int size) {
    Queue q;
    q.array = (int*)malloc(sizeof(int) * size);
    q.front = 0;
    q.rear = -1;
    q.maxSize = size;
    return q;
}

int isFull(Queue* q) {
    return q->rear == q->maxSize - 1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

void insertQueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Phan tu da day khong the them!\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Khong the lay phan tu ra khoi hang doi\n");
        return -1;
    }
    int remove = q->array[q->front];
    q->front++;
    return remove;
}

void displayQueue(Queue* q) {
    if (q->rear < q->front) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    free(q->array);
}
int main () {
    Queue myQueue = createQueue(5);

    printf("Front: %d\n", myQueue.front);
    printf("Rear: %d\n", myQueue.rear);
    printf("Queue truoc khi them: \n");
    displayQueue(&myQueue);

    insertQueue(&myQueue, 10);
    insertQueue(&myQueue, 20);
    insertQueue(&myQueue, 30);
    insertQueue(&myQueue, 40);
    insertQueue(&myQueue, 50);

    printf("Queue sau khi them:\n");
    displayQueue(&myQueue);
    printf("Queue sau khi lay phan tu dau:\n");
    int x = dequeue(&myQueue);
    printf("Phan tu duoc lay ra: %d\n", x);
    freeQueue(&myQueue);

    return 0;
}