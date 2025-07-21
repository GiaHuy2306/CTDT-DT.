#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    int priority;
    char dateLine[100];
}Task;

typedef struct SNode {
    Task task;
    struct SNode* next;
}SNode;

typedef struct DNode {
    Task task;
    struct DNode* pre;
    struct DNode* next;
}DNode;

void insertTask (SNode **head) {
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    printf("Nhap ID: ");
    scanf("%d", &newNode->task.id);
    getchar();
    printf("Nhap tieu de nhiem vu: ");
    fgets(newNode->task.title, sizeof(newNode->task.title),stdin);
    newNode->task.title[strcspn(newNode->task.title, "\n")] = '\0';
    printf("Nhap muc do uu tien nhiem vu: ");
    scanf("%d", &newNode->task.priority);
    getchar();
    printf("Nhap thoi gian hoan thanh nhiem vu: ");
    scanf("%s", &newNode->task.dateLine);
    getchar();
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }else {
        SNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Da them nhiem vu thanh cong\n");
}

void displayTask(SNode* head) {
    SNode* temp = head;
    if (head == NULL) {
        printf("Danh sach nhiem vu rong\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d\n", temp->task.id);
        printf("Tieu de: %s\n", temp->task.title);
        printf("Muc do uu tien %d\n", temp->task.priority);
        printf("Thoi gian hoan thanh: %s\n", temp->task.dateLine);
        temp = temp->next;
    }
}

void deleteTaskById(SNode** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return;
    }
    int id;
    printf("Nhap ID nhiem vu muon xoa: ");
    scanf("%d", &id);
    getchar();

    SNode* current = *head;
    SNode* pre = NULL;

    if (current != NULL && current->task.id == id) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->task.id != id) {
        pre = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay ID\n");
        return;
    }
    pre->next = current->next;
    free(current);
    printf("Da xoa thanh cong\n");
}

void updateTask(SNode** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the cap nhat\n");
        return;
    }
    int id;
    printf("Nhap ID can sua: ");
    scanf("%d", &id);
    getchar();
    SNode* temp = *head;
    while (temp != NULL && temp->task.id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay ID can sua\n");
        return;
    }
    printf("Nhap tieu de moi: ");
    fgets(temp->task.title, sizeof(temp->task.title), stdin);
    temp->task.title[strcspn(temp->task.title, "\n")] = '\0';
    printf("Nhap muc do uu tien moi: ");
    scanf("%d", &temp->task.priority);
    getchar();
    printf("Nhap thoi gian hoan thanh moi: ");
    scanf("%s", &temp->task.dateLine);
    getchar();
}

void tickTaskComplete(SNode** unComplete, DNode** complete) {
    int id;
    printf("Nhap ID muon danh dau: ");
    scanf("%d", &id);
    getchar();

    DNode* newDNode = (DNode*)malloc(sizeof(DNode));

    SNode* current = *unComplete;
    SNode* pre = NULL;

    if (current != NULL && current->task.id == id) {
        *unComplete = current->next;
        newDNode->task = current->task;
        free(current);
        return;
    }

    while (current != NULL && current->task.id != id) {
        pre = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Khong tim thay ID\n");
        return;
    }

    pre->next = current->next;
    newDNode->task = current->task;
    newDNode->pre = NULL;
    newDNode->next = *complete;
    free(current);
}

void sort(SNode* head) {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong\n");
        return;
    }
    for (SNode* i = head; i->next != NULL; i = i->next) {
        for (SNode* j = head; j->next != NULL; j = j->next) {
            if (j->task.priority > j->next->task.priority) {
                Task temp;
                temp = j->task;
                j->task = j->next->task;
                j->next->task = temp;
            }
        }
    }
}

void findTaskByTitle(SNode* head) {
    char title[100];
    printf("Nhap tieu de muon tim kiem: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    SNode *current = head;

    while (current != NULL && strcmp(current->task.title, title) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Khong tim thay\n");
        return;
    }
    printf("ID: %d\n", current->task.id);
    printf("Tieu de: %s\n", current->task.title);
    printf("Muc do uu tien: %d\n", current->task.priority);
    printf("Thoi gian hoan thanh: %s\n", current->task.dateLine);
}
int main () {
    int choice;
    SNode *head = NULL;
    DNode *head2 = NULL;

    do {
        printf("\n===== MENU QUAN LY NHIEM VU =====\n");
        printf("1. Them moi nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu theo do uu tien\n");
        printf("7. Tim kiem nhiem vu theo tieu de\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban (1-8): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                insertTask(&head);
                break;
            case 2:
                displayTask(head);
                break;
            case 3:
                deleteTaskById(&head);
                break;
            case 4:
                updateTask(&head);
                break;
            case 5:
                tickTaskComplete(&head, &head2);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                findTaskByTitle(head);
                break;
            case 8:
                printf("Da thoat!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);
    return 0;
}