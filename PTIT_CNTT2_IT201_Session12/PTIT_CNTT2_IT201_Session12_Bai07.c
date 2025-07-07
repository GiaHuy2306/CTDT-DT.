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

void sortDoublyLinkedListAscending(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }

        lptr = ptr1;
    } while (swapped);
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main () {
    Node* head = NULL;
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 5);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 0);
    head = insertAtTail(head, 4);
    printf("Danh sach truoc khi sap xep \n");
    display(head);

    printf("\n");
    sortDoublyLinkedListAscending(head);
    printf("Danh sach sau khi sap xep \n");
    display(head);

    return 0;
}