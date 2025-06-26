#include <stdio.h>
int sumArray(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n-1] + sumArray(arr, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = sumArray(arr, n);
    printf("%d\n", result);
    return 0;
}