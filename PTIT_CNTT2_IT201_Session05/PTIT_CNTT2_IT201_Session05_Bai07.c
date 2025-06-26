#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int n;
    printf("Nhap vao so luong phan tu fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("%d \n", fibonacci(i));
    }
}