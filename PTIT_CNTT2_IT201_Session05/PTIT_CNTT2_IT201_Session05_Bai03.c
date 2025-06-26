#include <stdio.h>

int factorial(int num) {
    if (num == 0) return 1;
    return num * factorial(num - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int factorialNum = factorial(num);
        printf("Factorial from 1 to %d is: %d\n", num, factorialNum);
    }
    return 0;
}