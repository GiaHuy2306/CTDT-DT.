#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int peek(Node* top) {
    if (top == NULL) {
        printf("Rong!\n");
        return -1;
    }
    return top->data;
}

void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int main() {
    Node* stackTop = NULL;

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);

    int topValue = peek(stackTop);
    if (topValue != -1) {
        printf("Top: %d\n", topValue);
    }

    return 0;
}

