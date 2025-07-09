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

void push(Stack* stack) {
    int value;
    do {
        printf("Nhap phan tu la so nguyen duong de them vao stack: ");
        scanf("%d", &value);
        if (value <= 0) {
            printf("Vui long nhap so nguyen duong\n");
        }
    }while (value <= 0);

    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Them thanh cong \n");
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack rong");
        return -1;
    }
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Ngan xep hien tai: \n");
    if (current == NULL) {
        printf("Rong");
    }
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}
int main () {
    Stack* myStack = createStack();
    push(myStack);
    push(myStack);
    push(myStack);
    printf("Stack truoc khi lay phan tu: ");
    printStack(myStack);

    printf("Stack sau khi lay phan tu: ");
    int poppedvalue = pop(myStack);
    if (poppedvalue != 1) {
        printf("Phan tu duoc lay ra la: %d", poppedvalue);
    }
    printStack(myStack);
    while (myStack->top != NULL) {
        Node* temp = myStack->top;
        myStack->top = myStack->top->next;
        free(temp);
    }
    free(myStack);
    return 0;
}