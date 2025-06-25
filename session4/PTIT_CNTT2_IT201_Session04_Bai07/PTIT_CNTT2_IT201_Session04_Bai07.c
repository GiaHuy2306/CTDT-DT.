#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int arr2[n];
    int len = n;
    int mid = n / 2;

    for (int i = 0; i < len; i++) {
        arr2[i] = arr[len - 1];
        len--;
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] == arr2[i]) {
            printf("Cap doi xung la (%d ; %d)", arr[i], arr2[i]);
        }
    }
}