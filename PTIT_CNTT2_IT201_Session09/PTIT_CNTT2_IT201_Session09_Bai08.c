#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("khong the cap phat bo nho");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteAtPosition(Node** head, int position) {
    if(*head == NULL) {
        printf("mang rong");
        return;
    }

    Node* temp = *head;
    if (position == 0) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Vi tri khong hop le");
        return;
    }
    Node* noteToDelete = temp->next;
    temp->next = noteToDelete->next;
    free(noteToDelete);
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
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* four = createNode(4);
    Node* five = createNode(5);

    head->next = second;
    second->next = third;
    third->next = four;
    four->next = five;

    traverse(head);
    deleteAtPosition(&head, 3);
    traverse(head);
    return 0;
}