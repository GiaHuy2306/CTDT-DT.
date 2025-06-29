#include <stdio.h>

int recursion(int number) {
    if (number == 0) {
        return 0;
    }
    recursion(number / 2);
    printf("%d", number % 2) ;
}
int main() {
    int n;
    scanf("%d", &n);

    recursion(n);
}