#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

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

Node* search (Node* head, int target) {
    Node* current = head;
    while(current != NULL) {
        if(current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main () {
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* four = createNode(4);
    struct Node* five = createNode(5);

    head->next = second;
    second->next = third;
    third->next = four;
    four->next = five;

    traverse(head);

    int target;
    printf("Nhap so can tim: ");
    scanf("%d", &target);

    Node* result = search(head, target);
    if (result != NULL) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}