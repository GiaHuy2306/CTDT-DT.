#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* insertAtTail(Node* head, int value) {
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* deleteByValue(Node* head, int value) {
    if (head == NULL) return NULL;

    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay gia tri %d trong danh sach.\n", value);
        return head;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) head->prev = NULL;
    }
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

int main () {
    Node* head = NULL;
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    printf("Danh sach truoc khi xoa: \n");
    display(head);

    deleteByValue(head, 2);
    printf("Danh sach sau khi xoa: \n");
    display(head);
}