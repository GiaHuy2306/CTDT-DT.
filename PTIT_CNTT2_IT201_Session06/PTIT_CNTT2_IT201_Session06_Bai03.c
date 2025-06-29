#include <stdio.h>

int sum (int n, int result) {
    if (n < 10) {
        return result += n;
    }
    result += n % 10;
    return sum (n / 10, result);
}

int main () {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Input khong hop le");
        return 0;
    }
    int result = sum (number, 0);
    printf("The sum of %d is %d", number, result);
    return 0;
}