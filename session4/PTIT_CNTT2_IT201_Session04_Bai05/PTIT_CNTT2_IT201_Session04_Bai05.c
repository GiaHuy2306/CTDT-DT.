#include <stdio.h>

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
    int start = 0;
    int end = n-1;
    int number;
    scanf("%d", &number);
    int flag = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (number == arr[mid]) {
            flag = 1;
            printf("Da tim thay");
            break;
        }
        else if (arr[mid] > number) {
            end = mid-1;
        }else if (arr[mid] < number) {
            start = mid+1;
        }
    }
    if (flag == 0) {
        printf("Khong tim thay");
    }
    return 0;
}