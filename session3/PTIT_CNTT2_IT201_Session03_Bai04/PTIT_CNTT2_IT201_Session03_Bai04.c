#include <stdio.h>
#include <stdlib.h>

int main () {
    int rows;
    int cols;
    printf("Enter rows and columns: ");
    scanf("%d",&rows);
    scanf("%d",&cols);
    do {
        if(rows <= 0) {
            printf("So luong hang khong hop le !\n");
            return 1;
        } else if(rows >= 1000) {
            printf("So luong hang khong hop le ! \n");
            return 1;
        }
    } while (rows <= 0 && rows >= 1000);

    do {
        if(cols <= 0) {
            printf("So luong cot khong hop le !\n");
            return 1;
        } else if(cols >= 1000) {
            printf("So luong cot khong hop le ! \n");
            return 1;
        }
    } while (cols <= 0 && cols >= 1000);

    int **arr;
    // Cap phat dong mang 2 chieu
    arr = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++) {
        arr[i] = (int*)malloc(cols*sizeof(int));
    }

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int max = arr[0][0];
    int min = arr[0][0];

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }else if(arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    for(int i=0;i<rows;i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
