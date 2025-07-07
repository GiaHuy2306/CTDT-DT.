#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prv;
}Node;

Node* createNode(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prv = NULL;
    if (head == NULL) {
        head->prv = newNode;
    }
    return newNode;
}

int main() {
    Node*head = NULL;

    head = createNode(head, 1);
    head = createNode(head, 2);
    head = createNode(head, 3);
    head = createNode(head, 4);
    head = createNode(head, 5);

    return 0;
}