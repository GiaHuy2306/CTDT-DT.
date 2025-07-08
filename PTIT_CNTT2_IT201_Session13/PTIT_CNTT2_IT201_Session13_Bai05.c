#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int max;
} Stack;

Stack createStack(int maxSize) {
    Stack stack;
    stack.data = (int*)malloc(sizeof(int) * maxSize);
    stack.top = -1;
    stack.max = maxSize;
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->max - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack day!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void reverseArray(int arr[], int size) {
    Stack stack = createStack(size);

    for (int i = 0; i < size; i++) {
        push(&stack, arr[i]);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = pop(&stack);
    }

    free(stack.data);
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int *array = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        printf("Phan tu thu [%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Mang ban dau: ");
    printArray(array, n);

    reverseArray(array, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(array, n);

    free(array);
    return 0;
}