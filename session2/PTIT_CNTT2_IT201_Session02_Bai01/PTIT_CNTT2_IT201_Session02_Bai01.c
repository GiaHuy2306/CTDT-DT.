#include  <stdio.h>

int main (){
    int n;
    int max;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    for(int i=1;i<n;i++) {
        if (max<arr[i]) {
            max=arr[i];
        }
    }
    printf("Maximum number is: %d",max);
}