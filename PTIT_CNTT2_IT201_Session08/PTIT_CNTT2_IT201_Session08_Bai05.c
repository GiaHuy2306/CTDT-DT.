#include <stdio.h>

int main () {
    int n;
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 1000);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}