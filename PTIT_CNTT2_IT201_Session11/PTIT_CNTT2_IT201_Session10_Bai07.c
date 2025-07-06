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

Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 0) {
        printf("khong hop le");
        return head;
    }
    if (position == 0) {
        return insert(head, data);
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;
    int index = 0;
    while (temp != NULL && index < position-1) {
        temp = temp->next;
        index++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    int n;
    int value;
    int num;
    int index;
    printf("nhap so luong phan tu:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d:", i+1);
        scanf("%d", &value);
        head = insert(head,value);
    }
    printf("nhap so can them: ");
    scanf("%d", &num);
    printf("nhap vi tri: ");
    scanf("%d", &index);
    head = insertAtPosition(head,num,index);
    print(head);
    return 0;
}