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

int getLen(Node* head) {
    int count = 0;
    Node* current = head;

    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    int length = getLen(head);

    printf("Do dai cua danh sach %d", length);

    return 0;
}