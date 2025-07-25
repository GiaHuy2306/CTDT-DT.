#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main () {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);
    return 0;
}