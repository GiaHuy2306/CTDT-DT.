#include <stdio.h>

void addEdge (int n, int arr[n][n], int startNode, int endNode) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == startNode && j == endNode) {
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
    int adjacencyMatrix[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    addEdge(3, adjacencyMatrix, 1, 0);
    addEdge(3, adjacencyMatrix, 1, 2);
    addEdge(3, adjacencyMatrix, 2, 0);

    printMaxtrix(3, adjacencyMatrix);
    return 0;
}