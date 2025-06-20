#include <stdio.h>

int main () {
    int n;
    scanf("%d",&n);
    if(n==0) {
        printf("So luong phan tu phai lon hon 0");
        return 1;
    }else if(n < 0) {
        printf("So luong phan tu khong duoc am");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Max = %d",max);
}