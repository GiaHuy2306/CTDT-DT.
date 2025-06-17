#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int number;
    scanf("%d",&number);
    for(int i=0;i<n-1;i++) {
        int num1,num2;
        for(int j=i+1;j<n;j++) {
            if(arr[i]+arr[j] == number) {
                num1 = arr[i];
                num2 = arr[j];
                printf("%d %d\n",num1,num2);
            }
        }
    }
}