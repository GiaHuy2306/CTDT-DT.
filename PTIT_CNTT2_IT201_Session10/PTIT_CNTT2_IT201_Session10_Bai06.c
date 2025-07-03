#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getlength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->next;
        length++;
    }
    return length;
}

void getMiddle(Node* head) {
    int length = getlength(head);
    int mid = length / 2;
    Node* current = head;

    for (int i = 0; i < mid; i++) {
        current = current->next;
    }
    if (current != NULL) {
        printf("Phan tu giua la: %d", current->data);
    }
}
void traversal(struct Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    getMiddle(head);
    return 0;
}