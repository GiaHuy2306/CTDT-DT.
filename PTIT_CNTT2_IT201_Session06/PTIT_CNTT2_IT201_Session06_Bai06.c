//
// Created by Admin on 6/27/2025.
//
#include <stdio.h>

int countWay(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return countWay(n - 1) + countWay(n - 2);
}

int main() {
    int  n;
    printf("Nhap so luong bac thang ");
    scanf("%d", &n);
    printf("%d", countWay(n));
    return 0;
}