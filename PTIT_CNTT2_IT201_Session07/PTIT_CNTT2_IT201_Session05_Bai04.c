#include <stdio.h>
#include <string.h>

int main () {
    char str[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    if (str == "") {
        printf("Chuoi khong hop le !\n");
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
}
