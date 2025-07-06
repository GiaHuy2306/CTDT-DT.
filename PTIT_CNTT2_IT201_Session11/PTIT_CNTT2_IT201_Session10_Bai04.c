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
        return newNode;
    }
}

Node* checkLen(Node* head) {
    int check = 0;
    while (head != NULL) {
        head = head->next;
        check++;
    }
    return check;
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
    int check = checkLen(head);
    printf("do dai : %d",check);
    return 0;
}