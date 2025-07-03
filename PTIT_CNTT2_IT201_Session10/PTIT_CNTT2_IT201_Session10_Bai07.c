#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Thêm vào cuối danh sách
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void traversal(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void sortAscending(Node* head) {
    if (head == NULL) return;

    Node* i = head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main() {
    Node* head = NULL;

    append(&head, 5);
    append(&head, 2);
    append(&head, 4);
    append(&head, 1);
    append(&head, 3);

    printf("Truoc khi sap xep:\n");
    traversal(head);

    sortAscending(head);

    printf("Sau khi sap xep:\n");
    traversal(head);

    return 0;
}
