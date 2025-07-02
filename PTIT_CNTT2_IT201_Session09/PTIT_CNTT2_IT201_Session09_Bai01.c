#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

    struct Node* p = head;
    while(p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return 0;
}