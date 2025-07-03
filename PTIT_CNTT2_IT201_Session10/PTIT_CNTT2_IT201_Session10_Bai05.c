#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* deleteValue(Node* head, int value) {
    Node* current = head;
    Node* pre = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (pre == NULL) {
                Node* temp = head;
                head = head->next;
                free(temp);
            } else {
                pre->next = current->next;
                free(current);
            }
            return head;
        }
        pre = current;
        current = current->next;
    }

    printf("Không tìm thấy giá trị cần xóa!\n");
    return head;
}

void traversal(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
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

    printf("Before Deletion:\n");
    traversal(head);

    head = deleteValue(head, 1);
    printf("After Deletion:\n");
    traversal(head);

    return 0;
}