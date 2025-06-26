#include <stdio.h>

int sum(int num) {
    if (num == 0) return 0;
    return num + sum(num - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int total = sum(num);
    printf("Tong tu 1 - %d la: %d", num, total);
}