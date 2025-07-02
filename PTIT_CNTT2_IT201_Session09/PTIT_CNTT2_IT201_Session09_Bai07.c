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

void insertList(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;

    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Vi tri khong hop le\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
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

    insertList(&head, 6, 2);

    traverse(head);

    return 0;
}