#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head -> prev = newNode;
    }
    return newNode;
}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head -> next;
    }
}

Node* deleteNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    if (head != NULL) {
        head -> prev = NULL;
    }
    free(temp);
    return head;
}

int main() {
    Node* head = NULL;
    int n;
    int value;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i+1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    head = deleteNode(head);
    print(head);
    return 0;
}