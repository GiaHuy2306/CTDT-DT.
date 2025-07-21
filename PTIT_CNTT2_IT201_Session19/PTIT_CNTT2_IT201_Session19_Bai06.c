#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
}QueueNode;

typedef struct {
    QueueNode* rear;
    QueueNode* front;
}Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node* createNode (int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void enqueue(Queue* q, Node* head) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = head;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

Queue* isEmpty(Queue* q) {
    return q->rear == NULL;
}

int searchBFS(Node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == x) return 1;

        if (current->left != NULL)
            enqueue(q, current->left);

        if (current->right != NULL)
            enqueue(q, current->right);
    }
    return 0;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    if (searchBFS(root, value)) {
        printf("True");
    }else {
        printf("False");
    }

    return 0;
}