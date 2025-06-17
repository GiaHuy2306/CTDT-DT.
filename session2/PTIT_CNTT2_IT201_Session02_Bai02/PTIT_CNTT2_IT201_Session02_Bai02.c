#include <stdio.h>
int main() {
    int n;
    int s;
    int count=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter number search: ");
    scanf("%d",&s);
    for(int i=0;i<n;i++) {
        if (s==arr[i]) {
            count++;
        }
    }
    printf("%d",count);
}