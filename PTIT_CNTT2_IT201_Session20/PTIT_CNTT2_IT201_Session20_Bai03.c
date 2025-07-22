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
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }else if (value > root->data) {
        root->right = insert(root->right, value);
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
    int n,  value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu so %d: ", i+1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    preorder(root);
    return 0;
}