#include <stdio.h>

void addEdge (int n, int arr[n][n], int firstNode, int secondNode) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == firstNode && j == secondNode) || (i == secondNode && j == firstNode)) {
                arr[i][j] = 1;
            }
        }
    }
}

void printMaxtrix( int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main () {
    char vertex[] = {'A','B','C'};
    int adjacencyMatrix[4][4] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}

    };
    addEdge(4, adjacencyMatrix, 0, 1);
    addEdge(4, adjacencyMatrix, 0, 2);
    addEdge(4, adjacencyMatrix, 1, 2);
    addEdge(4, adjacencyMatrix, 2, 3);

    printMaxtrix(4, adjacencyMatrix);
    return 0;
}