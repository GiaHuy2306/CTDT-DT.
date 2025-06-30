#include <stdio.h>

int main () {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le !\n");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int negative[n], zero[n], positive[n];
    int negaCount = 0, zeroCount = 0, posCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negative[negaCount++] = arr[i];
        }else if (arr[i] == 0) {
            zero[zeroCount++] = arr[i];
        }else {
            positive[posCount++] = arr[i];
        }
    }
    int index = 0;
    for (int i = 0; i < negaCount; i++) {
        arr[index++] = negative[i];
    }
    for (int i = 0; i < zeroCount; i++) {
        arr[index++] = zero[i];
    }
    for (int i = 0; i < posCount; i++) {
        arr[index++] = positive[i];
    }

    printf("After: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}