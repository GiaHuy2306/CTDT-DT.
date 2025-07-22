#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // dùng INT_MIN

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(Node* root) {
    if (root == NULL) return INT_MIN;

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    int maxSub = (maxLeft > maxRight) ? maxLeft : maxRight;
    return (root->data > maxSub) ? root->data : maxSub;
}

int main() {

    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int maxVal = findMax(root);
    printf("max value: %d\n", maxVal);

    return 0;
}
