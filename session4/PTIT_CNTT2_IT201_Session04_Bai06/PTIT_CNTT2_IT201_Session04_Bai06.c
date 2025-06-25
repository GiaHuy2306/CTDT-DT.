#include <stdio.h>
#include <string.h>

struct sinhVien {
    int id;
    char name[50];
    int age;
};

int main() {
    struct sinhVien sinhVien[5];
    for (int i = 0; i < 5; i++) {
        sinhVien[i].id = i+1;

        printf("Nhap ten sinh vien thu %d: ", i+1);
        fgets(sinhVien[i].name, 50, stdin);
        sinhVien[i].name[strcspn(sinhVien[i].name, "\n")] = '\0';

        printf("Nhap tuoi sinh vien thu %d: ", i+1);
        scanf("%d", &sinhVien[i].age);
        while (getchar() != '\n');
    }
    int findId;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &findId);
    for (int i = 0; i < 5; i++) {
        if (findId == sinhVien[i].id) {
            printf("ID: %d, Name: %s, Age: %d", sinhVien[i].id, sinhVien[i].name, sinhVien[i].age);
        }
    }
    return 0;
}