#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Reversed string: ");
    reverseString(str);

    return 0;
}