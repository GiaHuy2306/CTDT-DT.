#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* top;
}Stack;

Stack* createStack () {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}
int main () {
    Node* node1 = createNode(10);
    Stack* myStack = createStack();
    myStack->top = node1;
    if (myStack->top == NULL) {
        printf("Cap phat bo nho thanh cong va ngan xep\n");
    }else {
        printf("Ngan xep co dinh la: %d", myStack->top->data);
    }

    free(node1);
    free(myStack);
    return 0;
}