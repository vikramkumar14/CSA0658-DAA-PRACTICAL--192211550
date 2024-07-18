#include <stdio.h>

int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    rev = (rev * 10) + (num % 10);
    return reverseNumber(num / 10, rev);
}

int isPalindrome(int num) {
    if (num < 0)
        return 0;
    int rev = reverseNumber(num, 0);
    return (num == rev);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);

    return 0;
}
