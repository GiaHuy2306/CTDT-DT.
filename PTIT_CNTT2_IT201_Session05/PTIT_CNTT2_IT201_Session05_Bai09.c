#include <stdio.h>

int totalStep(int row, int col, int i, int j) {
    if (i==row-1 && j==col-1) {
        return 1;
    }
    if (i > row-1 || j > col-1) {
        return 0;
    }
    return totalStep(row, col, i, j+1) + totalStep(row, col, i+1, j);
}

int main() {
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int result = totalStep(row, col, 0, 0);
    printf("Total number of steps: %d", result);
    return 0;
}