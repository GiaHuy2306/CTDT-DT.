#include <stdio.h>

int totalStep(int row, int col, int i, int j, int backRow, int backCol) {
    if (i==row-1 && j==col-1) {
        return 1;
    }
    if (i > row-1 || j > col-1) {
        return 0;
    }
    if (backRow ==  i && backCol == j) {
        return 0;
    }
    return totalStep(row, col, i, j+1, backRow, backCol) + totalStep(row, col, i+1, j, backRow, backCol);
}

int main() {
    int row, col, backRow, backCol;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    printf("Enter number of backRow: ");
    scanf("%d", &backRow);
    printf("Enter number of backCol: ");
    scanf("%d", &backCol);

    int result = totalStep(row, col, 0, 0, backRow, backCol);
    printf("Total number of steps: %d", result);
    return 0;
}