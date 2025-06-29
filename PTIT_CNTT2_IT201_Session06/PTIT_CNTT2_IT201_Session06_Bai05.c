#include <stdio.h>

int minMax (int arr[], int n, int max, int min, int i) {
    if (i == n) {
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
        return 0;
    }
    if (arr[i] > max) {
        max = arr[i];
    }
    if (arr[i] < min) {
        min = arr[i];
    }
    i++;

    return minMax (arr, n, max, min, i);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    minMax (arr, n, arr[0], arr[0], 0);
    return 0;
}