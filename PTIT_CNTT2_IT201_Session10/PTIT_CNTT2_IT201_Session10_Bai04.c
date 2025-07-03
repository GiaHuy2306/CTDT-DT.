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

Node *deleteTail(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
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

    printf("Danh sach truoc khi xoa\n");
    traversal(head);

    deleteTail(&head);
    printf("Danh sach sau khi xoa\n");
    traversal(head);

    return 0;
}