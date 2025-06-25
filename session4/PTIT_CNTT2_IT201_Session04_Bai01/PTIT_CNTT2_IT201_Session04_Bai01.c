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
    int flag;
    for (int i = 0; i < n; i++) {
        if (arr[i] == s) {
            flag = i;
            printf("%d\n", flag);
            return 1;
        }
    }
    return 0;
}