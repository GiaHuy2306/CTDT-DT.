#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int evaluatePostfix(char expr[]) {
    int len = strlen(expr);
    Stack stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            push(&stack, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = 0;

            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Loi: chia cho 0!\n");
                        exit(1);
                    }
                    result = a / b;
                    break;
            }
            push(&stack, result);
        }
    }

    int finalResult = pop(&stack);
    free(stack.data);
    return finalResult;
}

// Hàm chính
int main() {
    char expr[100];

    printf("Nhap bieu thuc: ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Ket qua: %d\n", result);

    return 0;
}
