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

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;

    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main () {
    Node* root = NULL;
    int n, value;

    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    preorder(root);

    return 0;
}