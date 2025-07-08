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

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char value) {
    if (stack->top < stack->max - 1) {
        stack->data[++stack->top] = value;
    }
}

char pop(Stack *stack) {
    if (isEmpty(stack)) return '\0';
    return stack->data[stack->top--];
}

char peek(Stack *stack) {
    if (isEmpty(stack)) return '\0';
    return stack->data[stack->top];
}

bool isValidBrackets(char *expr) {
    int len = strlen(expr);
    Stack stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&stack)) {
                free(stack.data);
                return false;
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                free(stack.data);
                return false;
            }
        }
    }

    bool result = isEmpty(&stack);
    free(stack.data);
    return result;
}

// Hàm chính
int main() {
    char expr[100];

    printf("Nhap bieu thuc can kiem tra: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (isValidBrackets(expr)) {
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
    }

    return 0;
}
