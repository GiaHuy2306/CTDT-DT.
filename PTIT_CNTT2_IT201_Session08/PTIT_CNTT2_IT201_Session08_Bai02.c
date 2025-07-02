#include <stdio.h>
// Do phuc tap thoi gian tot nhat O(1), xau O(log n)
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid + 1;
        }else if (arr[mid] < target) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return -1;
}

int main () {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int target;
    printf("Nhap gia tri muon tim kiem: ");
    scanf("%d", &target);

    int index = binarySearch(a, n, target);

    if (index == -1) {
        printf("khong tim thay");
    }else {
        printf("Vi tri thu %d", index);
    }
    return 0;
}