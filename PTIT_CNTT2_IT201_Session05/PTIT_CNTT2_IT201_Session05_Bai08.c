#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringtoInt (char str[], int index, int len, int *error) {
    if (index == len) return 0;

    char c = str[index];
    if (!isdigit(c)) {
        *error = 1;
        return 0;
    }

    int digit = c - '0';
    int power = len - index - 1;

    return digit * power10(power) + stringtoInt(str, index + 1, len, error);
}

int power10(int n) {
    if (n == 0) return 1;

    return 10 *  power10(n-1);
}

int main () {
    char str[100];
    printf("Nhap chuoi chu so: ");
    scanf("%s", str);

    int len = strlen(str);
    int error = 0;
    int result = stringtoInt(str, 0, len, &error);

    if (error) {
        printf("input khong hop le");
    }else {
        printf("Output: %d", result);
    }
    return 0;
}