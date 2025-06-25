#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5
#define NAME_LEN 50

struct Student {
    int id;
    char name[NAME_LEN];
    int age;
};

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int containsIgnoreCase(char name[], char keyword[]) {
    char tempName[NAME_LEN];
    strcpy(tempName, name);
    toLowerCase(tempName);

    char tempKey[NAME_LEN];
    strcpy(tempKey, keyword);
    toLowerCase(tempKey);

    return strstr(tempName, tempKey) != NULL;
}

int main() {
    struct Student students[MAX];

    for (int i = 0; i < MAX; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar();
        printf("Name: ");
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &students[i].age);
        getchar();
    }

    char keyword[NAME_LEN];
    printf("\nEnter name to search: ");
    scanf(" %[^\n]", keyword);

    printf("\nStudents matched:\n");
    for (int i = 0; i < MAX; i++) {
        if (containsIgnoreCase(students[i].name, keyword)) {
            printf("{ id: %d, name: \"%s\", age: %d }\n",
                   students[i].id, students[i].name, students[i].age);
        }
    }

    return 0;
}
