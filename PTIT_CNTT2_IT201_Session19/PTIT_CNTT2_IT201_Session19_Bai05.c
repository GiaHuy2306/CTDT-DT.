#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode (int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;

    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int findDFS(int value, Node* root) {
    if (root == NULL) return 0;

    if (root->data == value) return 1;

    return findDFS(value, root->left) || findDFS(value, root->right);
}

int main () {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    preorderTraversal(root);

    Node* findValue = findDFS(3, root);

    if (findValue) {
        printf("True");
    }else {
        printf("False");
    }
    free(root);
    return 0;
}