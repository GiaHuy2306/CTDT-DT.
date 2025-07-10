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
    displayQueue(&myQueue);

    freeQueue(&myQueue);

    return 0;
}