#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char type[100];
    int Duration;
    int calories;
    char date[100];
}Health;

typedef struct Node{
    Health health;
    struct Node* next;
}Node;

Node* head = NULL;

Node *insert(Node *head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("nhap id: ");
    scanf("%d",&newNode->health.id);
    getchar();
    printf("nhap type: ");
    fgets(newNode->health.type,100,stdin);
    newNode->health.type[strcspn(newNode->health.type,"\n")] = '\0';
    printf("nhap Duration: ");
    scanf("%d",&newNode->health.Duration);
    getchar();
    printf("nhap calories: ");
    scanf("%d",&newNode->health.calories);
    getchar();
    printf("nhap date: ");
    fgets(newNode->health.date,100,stdin);
    newNode->health.date[strcspn(newNode->health.date, "\n")] = '\0';
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    }else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("da them\n");
    return head;
}

void show(Node *head){
    if(head == NULL) {
        printf("rong");
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        printf("id: %d\n",temp->health.id);
        printf("type: %s\n",temp->health.type);
        printf("Duration: %d\n",temp->health.Duration);
        printf("calories: %d\n",temp->health.calories);
        printf("date: %s\n",temp->health.date);
        temp = temp->next;
    }
}

Node *delete(Node **head) {
    if(*head == NULL) {
        printf("rong");
        return *head;
    }
    int id;
    printf("nhap id muon xoa: ");
    scanf("%d",&id);
    getchar();
    Node *temp = *head, *prev = NULL;
    while (temp !=NULL ) {
       if(temp->health.id == id) {
           if(prev == NULL) {
               *head = temp->next;
           }else {
               prev->next = temp->next;
           }
           free(temp);
           printf("da xoa");
           return*head;
       }
        prev = temp;
        temp = temp->next;
    }
    printf("khong tim thay\n");
    return *head;
}

void update(Node *head) {
    int id;
    char newType[100];
    char newDate[100];
    int newDuration;
    int newCalories;
    printf("nhap id muon cap nhat: ");
    scanf("%d",&id);
    getchar();
    while (head != NULL) {
        if(head->health.id == id) {
            printf("nhap type moi: ");
            fgets(newType,100,stdin);
            newType[strcspn(newType, "\n")] = '\0';
            printf("nhap Duration moi: ");
            scanf("%d",&newDuration);
            getchar();
            printf("nhap calories moi: ");
            scanf("%d",&newCalories);
            getchar();
            printf("nhap date moi: ");
            fgets(newDate,100,stdin);
            newDate[strcspn(newDate, "\n")] = '\0';

            strcpy(head->health.type,newType);
            strcpy(head->health.date,newDate);
            head->health.calories = newCalories;
            head->health.Duration = newDuration;
            return;
        }
        head = head->next;
    }
    printf("khong tim thay\n");
}

void sort(Node *head) {
    for(Node *i = head; i != NULL; i = i->next) {
        Node *min = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->health.calories < min->health.calories) {
                min = j;
            }
            if (min != i) {
                Health temp = min->health;
                i->health = min->health;
                min->health = temp;
            }
        }
    }
    printf("da sap xep\n");
}

void find(Node *head) {
    if(head == NULL) {
        printf("rong");
        return;
    }
    char checkType[100];
    getchar();
    printf("nhap type can tim: ");
    fgets(checkType,100,stdin);
    checkType[strcspn(checkType, "\n")] = '\0';
    while (head != NULL) {
        if(strcmp(checkType,head->health.type) == 0) {
            printf("id %d",head->health.id);
            printf("type: %s\n",head->health.type);
            printf("Duration: %d\n",head->health.Duration);
            printf("calories: %d\n",head->health.calories);
            printf("date: %s\n",head->health.date);
            return;
        }
        head = head->next;
    }
    printf("khong tim thay\n");
}


int main(void) {
    int choose;
    do {
        printf("1.Them hoat dong trong ngay\n");
        printf("2.Hien thi danh sach hoat dong\n");
        printf("3.Xoa hoat dong\n");
        printf("4.Cap nhat trong tin hoat dong\n");
        printf("5.Thong ke tong calo tieu thu tren ngay\n");
        printf("6.Sap xep hoat dong\n");
        printf("7 Tim kiem hoat dong\n");
        printf("8.Thoat chuong trinh\n");
        printf("nhap lua chon");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                head = insert(head);
                break;
            case 2:
                show(head);
                break;
            case 3:
                head = delete(&head);
                break;
            case 4:
                update(head);
                break;
            case 5:
                break;
            case 6:
                sort(head);
                break;
            case 7:
                find(head);
                break;
            case 8:
                printf("da thoat chuong trinh");
                break;
        }

    }while (choose != 8);
    return 0;
}
Viết cho Hải Dũng
