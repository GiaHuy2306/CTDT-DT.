#include <stdio.h>
#include <string.h>

int checkPalindrome(char arr[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (arr[start] != arr[end]) {
        return 0;
    }
    return checkPalindrome(arr, start+1, end-1);
}

int main () {
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    int len = strlen(string);
    string[strcspn(string, "\n")] = 0;

    int result = checkPalindrome(string, 0, len-1);
    if (result == 0) {
        printf("The string is not palindrome.\n");
    }else {
        printf("The string is palindrome.\n");
    }
}
