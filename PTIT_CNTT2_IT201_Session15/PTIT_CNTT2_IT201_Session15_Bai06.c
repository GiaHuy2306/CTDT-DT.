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

int isInceasingByOne(Queue* q) {
    if (q->rear - q->front+1 < 2) {
        return 1;
    }

    int prv = dequeue(q);
    while (!isEmpty(q)) {
        int current = dequeue(q);
        if (current != prv + 1) {
            return 0;
        }
        prv = current;
    }
    return 1;
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
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    Queue myQueue = createQueue(n);

    printf("Front: %d\n", myQueue.front);
    printf("Rear: %d\n", myQueue.rear);
    printf("Queue truoc khi them: \n");
    displayQueue(&myQueue);

    for (int i = 0; i < n; i++) {
        printf("Nhap so nguyen duong: ");
        scanf("%d", &value);
        insertQueue(&myQueue, value);
    }

    printf("Queue sau khi them:\n");
    displayQueue(&myQueue);
    printf("Queue sau khi lay phan tu dau:\n");
    int x = dequeue(&myQueue);
    printf("Phan tu duoc lay ra: %d\n", x);

    if (isInceasingByOne(&myQueue)) {
        printf("True");
    }else {
        printf("False");
    }

    freeQueue(&myQueue);

    return 0;
}