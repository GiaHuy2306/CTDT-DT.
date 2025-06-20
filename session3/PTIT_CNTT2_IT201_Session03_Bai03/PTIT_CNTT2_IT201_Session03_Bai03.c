#include <stdio.h>
#include <stdlib.h>

int main() {
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
    int sum = 0;
    int avg;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        avg = sum/n;
    }
    printf("avenger = %d\n",avg);
    free(arr);
}
