#include <stdio.h>

int countUp(int num, int st) {
    if (num == 0) return 0;
    printf("%d\n", st);
    st++;
    return countUp(num - 1, st);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int start = 1;
    countUp(num, start);
    return 0;
}