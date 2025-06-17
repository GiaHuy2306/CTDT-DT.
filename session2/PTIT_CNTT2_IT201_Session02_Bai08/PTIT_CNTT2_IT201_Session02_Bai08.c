#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=n;i>0;i--) {
        int temp=arr[i];
        if(arr[i]<arr[i-1]) {
            temp=arr[i-1];
            printf("%d\n",temp);
        }
    }
}