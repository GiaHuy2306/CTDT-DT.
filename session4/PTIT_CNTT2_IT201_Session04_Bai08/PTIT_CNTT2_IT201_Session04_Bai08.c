#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int s;
    scanf("%d", &s);
    int index;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == s) {
            index = i;
            printf("%d\n", index);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Khong tim thay phan tu");
    }

    return 0;
}