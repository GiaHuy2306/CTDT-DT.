#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* insert(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

int find(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    int n;
    int value;
    int num;
    Node *head = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i+1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap so can tim: ");
    scanf("%d", &num);
    int result = find(head, num);
    if (result == 1) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}