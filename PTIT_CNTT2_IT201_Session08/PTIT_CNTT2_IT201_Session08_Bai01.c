#include <stdio.h>

// Do phuc tap thoi gian O(n)
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i+1;
        }
    }
    return -1;
}

int main () {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Nhap gia tri muon tim: ");
    scanf("%d", &target);

    int index = linearSearch(arr, n, target);

    if (index != -1) {
        printf("Vi tri thu %d", index);
    }else {
        printf("Khong tim thay");
    }
    return 0;
}