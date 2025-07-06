#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node* deletePosition(Node* head,int position) {
    if (head == NULL || position < 0) {
        printf("khong hop le\n");
        return head;
    }
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    int index = 0;
    Node* temp = head;
    while (temp != NULL && index < position) {
        temp = temp->next;
        index++;
    }
    if (temp == NULL) {
        printf("khong hop le\n");
        return head;
    }
    if (temp != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    return head;
}

int main() {
    Node* head = NULL;
    int n;
    int value;
    int index;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ",i+1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap vi tri: ");
    scanf("%d", &index);
    head = deletePosition(head, index);
    print(head);
    return 0;
}