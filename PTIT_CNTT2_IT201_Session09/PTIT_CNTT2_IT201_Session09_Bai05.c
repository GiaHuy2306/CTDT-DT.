#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void insertAtHead(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void traverse(Node* head) {
    Node* current = head;
    int i = 1;
    while(current != NULL) {
        printf("Node %d %d\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("NULL");
    printf("\n");
}

int main () {
    Node* head = NULL;

    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    insertAtHead(&head, 4);
    insertAtHead(&head, 5);

    traverse(head);

    return 0;
}