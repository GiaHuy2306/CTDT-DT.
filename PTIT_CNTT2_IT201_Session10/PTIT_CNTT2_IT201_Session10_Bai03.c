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

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
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

    insertAtEnd(head, 6);

    traversal(head);
    return 0;
}