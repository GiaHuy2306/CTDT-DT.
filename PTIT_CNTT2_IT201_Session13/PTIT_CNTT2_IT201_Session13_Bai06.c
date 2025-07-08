#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int max;
} Stack;

Stack createStack(int maxSize) {
    Stack stack;
    stack.data = (char*)malloc(sizeof(char) * maxSize);
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

// Push ký tự vào stack
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack đầy!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; // Ký tự rỗng
    }
    return stack->data[stack->top--];
}

bool isPalindrome(char str[]) {
    int len = strlen(str);
    Stack stack = createStack(len);

    for (int i = 0; i < len / 2; i++) {
        push(&stack, str[i]);
    }

    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    for (int i = start; i < len; i++) {
        char c = pop(&stack);
        if (str[i] != c) {
            free(stack.data);
            return false;
        }
    }

    free(stack.data);
    return true;
}

int main() {
    char str[100];

    printf("Nhap chuoi de kiem tra: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("Chuoi \"%s\" la chuoi doi xung\n", str);
    } else {
        printf("Chuoi \"%s\" khong phai la chuoi doi xung\n", str);
    }

    return 0;
}