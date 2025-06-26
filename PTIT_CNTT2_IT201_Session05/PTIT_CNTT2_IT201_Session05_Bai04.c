#include <stdio.h>

int sum(int firstNumber, int secondNumber) {
    if (firstNumber >= secondNumber) {
        return secondNumber;
    }
    return firstNumber + sum(firstNumber + 1, secondNumber);
}

int main() {
    int firstNum;
    printf("Enter a number 1: ");
    scanf("%d", &firstNum);

    int secondNum;
    printf("Enter a number 2: ");
    scanf("%d", &secondNum);

    if (firstNum < 0 || secondNum < 0) {
        printf("First and second numbers must be non-negative.\n");
        return 1;
    }else {
        int result = sum(firstNum, secondNum);
        printf("The sum of %d and %d is: %d\n", firstNum, secondNum, result);
    }
    return 0;
}