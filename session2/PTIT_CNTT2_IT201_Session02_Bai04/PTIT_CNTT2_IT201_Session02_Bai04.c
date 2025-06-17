#include <stdio.h>

int main () {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int position;
    printf("Enter index number edit: ");
    scanf("%d",&position);
    int valueEdit;
    printf("Enter value edit: ");
    scanf("%d",&valueEdit);
    arr[position] = valueEdit;

    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}