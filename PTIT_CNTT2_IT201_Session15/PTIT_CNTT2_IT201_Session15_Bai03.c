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

void displayQueue(Queue* q) {
    if (q->rear < q->front) {
        printf("Queue rong\n");
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
    insertQueue(&myQueue, 60);

    printf("Queue sau khi them:\n");
    displayQueue(&myQueue);

    if (isEmpty(&myQueue)) {
        printf("True");
    }else {
        printf("False");
    }
    freeQueue(&myQueue);

    return 0;
}