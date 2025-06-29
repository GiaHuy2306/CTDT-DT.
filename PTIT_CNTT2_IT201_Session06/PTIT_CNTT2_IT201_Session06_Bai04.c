#include <stdio.h>

int  tower(int n, char a, char b, char c) {
    if (n == 0) {
        return 0;
    }
    tower(n - 1, a, c, b);
    printf("di chuyen tu %c den %c \n", a, c);
    tower(n - 1, b, a, c);
}

int main () {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    if (n == 1) {
        printf("Dia 1 di chuyen tu A sang C");
        return 0;
    }
    tower(n, 'a', 'b', 'c');
    return 0;
}