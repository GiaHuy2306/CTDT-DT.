#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CUSTOMER 100
#define MAX_NAME 31

typedef struct {
    char** array;
    int front;
    int rear;
    int count;
    int maxSize;
}Queue;

Queue createQueue(int size) {
    Queue q;
    q.array = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        q.array[i] = (char*)malloc(sizeof(char) * MAX_NAME);
        q.array[i][0] = '\0';
    }
    q.front = 0;
    q.rear = -1;
    q.maxSize = size;
    return q;
}

int isFull(Queue* q) {
    return q->count == q->maxSize;
}

int isEmpty(Queue* q) {
    return q->count == 0;
}

void enqueue(Queue* q, const char* name) {
    if (isFull(q)) {
        printf("Hang doi da day khong the them!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->maxSize;
    strncpy(q->array[q->rear], name, MAX_NAME - 1);
    q->array[q->rear][MAX_NAME - 1] = '\0';
    q->count++;
    printf("Them thanh cong khach hang\n");
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong khong the phuc vu");
        return;
    }
    printf("Phuc vu khach: %s\n", q->array[q->front]);
    q->front = (q->front + 1) % q->maxSize;
    q->count--;
}

void displayQueue(Queue* q) {
    if (q->rear < q->front) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Danh sach hang doi\n");
    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%s\n", q->array[index]);
        index = (index + 1) % q->maxSize;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    for (int i = 0; i < q->maxSize; i++) {
        free(q->array[i]);
    }
    free(q->array);
}

int main () {
    Queue myQueue = createQueue(CUSTOMER);
    int choice;
    char name[MAX_NAME];

    do {
        printf("1. Them khach hang vao danh sach doi\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach hang doi\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (!isFull(&myQueue)) {
                    printf("Nhap ten khach hang: ");
                    fgets(name, MAX_NAME, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    enqueue(&myQueue, name);
                }else {
                    enqueue(&myQueue, "");
                }
                break;
            case 2:
                dequeue(&myQueue);
                break;
            case 3:
                displayQueue(&myQueue);
                break;
            case 4:
                printf("Thoat chuong trinh\n");
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 4);
    return 0;
}