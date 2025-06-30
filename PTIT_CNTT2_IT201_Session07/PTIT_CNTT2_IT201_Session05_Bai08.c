#include <stdio.h>

int main () {
    int rows, cols, k;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Before \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Nhap so cot muon sap xep: ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("So cot khong hop le !");
        return 0;
    }

    int temp[cols];
    for (int i = 0; i < cols; i++) {
        temp[i] = arr[i][k];
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    for (int i = 0; i < cols; i++) {
        arr[i][k] = temp[i];
    }

    printf("After \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}