#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int top;
  int max;
}Stack;

Stack createStack(int maxSize) {
  Stack stack;
  stack.data = (int*)malloc(sizeof(int)*maxSize);
  stack.top = -1;
  stack.max = maxSize;
  return stack;
}

int isEmpty(Stack *stack) {
  return stack->top == -1;
}

int isFull(Stack *stack) {
  return stack->top == stack->max-1;
}

void print(Stack *stack) {
  printf("Do dai cua stack: %d\n", stack->max);
  printf("Top: %d\n", stack->top);
  for (int i = 0; i <= stack->top; i++) {
    printf("%d", stack->data[i]);
  }
}
int main () {
  Stack myStack = createStack(5);
  print(&myStack);

  free(myStack.data);
  return 0;
}