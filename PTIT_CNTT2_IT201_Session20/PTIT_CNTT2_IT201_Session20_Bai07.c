#include <stdio.h>
#include <stdlib.h>

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

typedef struct QNode {
    Node* data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* data) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = data;
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
    QNode* temp = q->front;
    Node* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void deleteDeepest(Node* root, Node* delNode) {
    Queue* q = createQueue();
    enqueue(q, root);
    Node* temp;

    while (!isEmpty(q)) {
        temp = dequeue(q);
        if (temp->left) {
            if (temp->left == delNode) {
                temp->left = NULL;
                free(delNode);
                return;
            } else enqueue(q, temp->left);
        }
        if (temp->right) {
            if (temp->right == delNode) {
                temp->right = NULL;
                free(delNode);
                return;
            } else enqueue(q, temp->right);
        }
    }
}

void deleteNode(Node* root, int value) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            free(root);
            root = NULL;
            return;
        } else {
            printf("Value not found\n");
            return;
        }
    }

    Queue* q = createQueue();
    enqueue(q, root);

    Node *target = NULL, *temp = NULL;

    while (!isEmpty(q)) {
        temp = dequeue(q);
        if (temp->data == value) target = temp;

        if (temp->left) enqueue(q, temp->left);
        if (temp->right) enqueue(q, temp->right);
    }

    if (target != NULL) {
        int deepestValue = temp->data;  // `temp` now holds the last node
        deleteDeepest(root, temp);      // delete last node
        target->data = deepestValue;    // replace target value
        printf("Deleted node with value: %d\n", value);
    } else {
        printf("Value %d not found in the tree.\n", value);
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {

    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Preorder before delete:\n");
    preorder(root);
    printf("\n");

    int deleteValue = 3;
    printf("deleteValue: %d\n", deleteValue);
    deleteNode(root, deleteValue);

    printf("Preorder after delete:\n");
    preorder(root);
    printf("\n");

    return 0;
}
