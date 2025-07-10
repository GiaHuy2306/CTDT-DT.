#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 31
#define MAX_QUEUE 100

typedef struct {
    char name[MAX_NAME];
    int age;
} Customer;

typedef struct {
    Customer array[MAX_QUEUE];
    int front;
    int rear;
    int count;
} Queue;

// Khoi tao hang doi
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Kiem tra rong
int isEmpty(Queue* q) {
    return q->count == 0;
}

// Kiem tra day
int isFull(Queue* q) {
    return q->count == MAX_QUEUE;
}

// Them khach hang vao hang doi
void enqueue(Queue* q, const char* name, int age) {
    if (isFull(q)) {
        printf("Hang doi da day, khong the them khach '%s'.\n", name);
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    strncpy(q->array[q->rear].name, name, MAX_NAME - 1);
    q->array[q->rear].name[MAX_NAME - 1] = '\0';
    q->array[q->rear].age = age;
    q->count++;
}

// Phuc vu khach hang dau tien
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }
    Customer c = q->array[q->front];
    printf("Phuc vu khach: %s (Tuoi: %d)\n", c.name, c.age);
    q->front = (q->front + 1) % MAX_QUEUE;
    q->count--;
}

// Hien thi danh sach hang doi
void displayQueue(Queue* q, const char* label) {
    printf("Danh sach %s (%d nguoi):\n", label, q->count);
    if (isEmpty(q)) {
        printf(" - (trong)\n");
        return;
    }
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf(" - %s (Tuoi: %d)\n", q->array[idx].name, q->array[idx].age);
        idx = (idx + 1) % MAX_QUEUE;
    }
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    char name[MAX_NAME];
    int age;

    do {
        printf("1. Them khach hang moi\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach hang doi\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Nhap tuoi: ");
                scanf("%d", &age);
                getchar();

                if (age >= 60) {
                    enqueue(&queueOld, name, age);
                } else {
                    enqueue(&queueNormal, name, age);
                }
                break;

            case 2:
                if (!isEmpty(&queueOld)) {
                    dequeue(&queueOld);
                } else if (!isEmpty(&queueNormal)) {
                    dequeue(&queueNormal);
                } else {
                    printf("Khong co khach nao de phuc vu.\n");
                }
                break;

            case 3:
                displayQueue(&queueOld, "Nguoi gia (>=60)");
                displayQueue(&queueNormal, "Nguoi thuong (<60)");
                break;

            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }

    } while (choice != 4);

    return 0;
}
