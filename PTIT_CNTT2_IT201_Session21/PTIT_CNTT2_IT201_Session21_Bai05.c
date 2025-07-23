#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge (int n, Node* arr[n], int firstNode, int secondNode) {
    if (firstNode == secondNode) {
        return;
    }
    for (int i = n; i >= 0; i--) {
        if (i == firstNode) {
            Node* newValue = createNode(secondNode);
            newValue->next = arr[i];
            arr[i] = newValue;
            return;
        }
    }
}

void printMaxtrix(int n, Node* arr[n]) {
    Node* current = NULL;
    for (int i = 0; i < n; i++) {
        current = arr[i];
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main () {
    Node* arr[3] = {
    NULL, NULL, NULL
    };

    addEdge(3, arr, 1, 2);
    addEdge(3, arr, 2, 1);
    addEdge(3, arr, 0, 1);
    addEdge(3, arr, 1, 0);


    printMaxtrix(3, arr);

    return 0;
}