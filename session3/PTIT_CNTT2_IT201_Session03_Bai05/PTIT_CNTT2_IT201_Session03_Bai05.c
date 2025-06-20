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

    int **maxtrix;
    // Cap phat dong mang 2 chieu
    maxtrix = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++) {
        maxtrix[i] = (int*)malloc(cols*sizeof(int));
    }

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            scanf("%d",&maxtrix[i][j]);
        }
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d ",maxtrix[i][j]);
        }
        printf("\n");
    }
    int totalMain = 0;
    int totalSub = 0;

    int minDim = rows < cols ? rows : cols;
    for(int i=0;i<minDim;i++) {
        totalMain += maxtrix[i][i];
    }
    if (rows != cols) {
        printf("Tong duong cheo chinh %d\n",totalMain);
        printf("Khong co duong cheo phu\n");
        return 1;
    }
    for(int i=rows - 1;i>=0;i--) {
        totalSub += maxtrix[i][i];
    }
    if (rows == cols) {
        printf("Tong duong cheo chinh %d\n",totalMain);
        printf("Tong duong cheo phu %d\n", totalSub);
    }
    for(int i=0;i<rows;i++) {
        free(maxtrix[i]);
    }
    free(maxtrix);
}