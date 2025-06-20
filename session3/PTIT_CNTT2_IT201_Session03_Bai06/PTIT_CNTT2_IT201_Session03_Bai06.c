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
    int m;
    printf("Nhap so phan tu muon them: ");
    scanf("%d",&m);
    int* new_arr = (int*) realloc(arr, (n+m) * sizeof(int));
    arr= new_arr;
    for(int i=n;i<n+m;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n+m;i++) {
        printf("%d ",arr[i]);
    }
}