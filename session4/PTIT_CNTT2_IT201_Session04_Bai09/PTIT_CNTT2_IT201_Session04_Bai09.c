#include <stdio.h>

int binarySearch(int arr[], int low, int high, int search) {
    if (low <= high) {
        int mid = (high + low) / 2;
        if (search == arr[mid]) {
            return mid;
        }else if (search  < arr[mid]) {
            return binarySearch(arr, low, mid - 1, search);
        }else {
            return binarySearch(arr, mid + 1, high, search);
        }
    }else {
        return -1;
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    int findElement;
    scanf("%d", &findElement);
    int result = binarySearch(arr, 0, n-1, findElement);
    if (result != -1) {
        printf("Da tim thay phan tu\n");
    }else {
        printf("Khong tim thay phan tu\n");
    }
    return 0;
}