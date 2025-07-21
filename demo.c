#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    char nameSong[31];
}Song;

typedef struct {
    Song data[MAX];
    int top;
}Stack;

typedef struct {
    Song data[MAX];
    int front, rear, count;
}Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isQueueEmpty(Queue *q) {
    return q->count == 0;
}

int isQueueFull(Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue* q, Song s) {
    if (!isQueueFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = s;
        q->count++;
    }else {
        printf("Hang doi da day\n");
    }
}

Song dequeue(Queue* q) {
    Song temp = {"NULL"};
    if (!isQueueEmpty(q)) {
        temp = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
    }
    return temp;
}

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Song song) {
    if (!isStackFull(s)) {
        s->data[++s->top] = song;
    }
}

Song pop(Stack *s) {
    Song temp = {"NULL"};
    if (!isStackEmpty(s)) {
        temp = s->data[s->top--];
    }
    return temp;
}

void displayStack(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Chua co bai hat nao\n");
    }else {
        printf("Danh sach da phat: \n");
        for (int i = 0; i<= s->top; i++) {
            printf("%d. %s\n", i+1, s->data[i].nameSong);
        }
    }
}
int main() {
    Queue nextQueue;
    Stack historyStack;

    initQueue(&nextQueue);
    initStack(&historyStack);

    int choice;
    Song song;

    do {
        printf("\n MUSIC PLAYER \n");
        printf("1. ADD \n");
        printf("2. PLAY NEXT\n");
        printf("3. PLAY PREVIOUS\n");
        printf("4. HISTORY\n");
        printf("5. EXIT \n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten bai hat: ");
                fgets(song.nameSong, sizeof(song.nameSong), stdin);
                song.nameSong[strcspn(song.nameSong, "\n")] = '\0';
                enqueue(&nextQueue, song);
                printf("Da them: %s\n", song.nameSong);
                break;

            case 2:
                if (!isQueueEmpty(&nextQueue)) {
                    Song current = dequeue(&nextQueue);
                    push(&historyStack, current);
                    printf(" Dang phat: %s\n", current.nameSong);
                } else {
                    printf("Khong con bai nao trong hang doi.\n");
                }
                break;

            case 3:
                if (historyStack.top >= 1) {
                    Song last = pop(&historyStack);
                    Song prev = historyStack.data[historyStack.top];
                    printf(" Phat lai bai: %s\n", prev.nameSong);
                    push(&historyStack, last);
                } else {
                    printf("Khong co bai nao de quay lai.\n");
                }
                break;

            case 4: // HISTORY
                displayStack(&historyStack);
                break;

            case 5: // EXIT
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon nao khong hop le.\n");
        }

    } while (choice != 5);

    return 0;
}
