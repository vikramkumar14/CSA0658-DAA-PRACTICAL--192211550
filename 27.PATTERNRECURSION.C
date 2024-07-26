#include <stdio.h>

void printPattern(int n, int i) {
    if (i > n) return;
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
    printf("\n");
    printPattern(n, i + 1);
}

int main() {
    int n = 4;
    printPattern(n, 1);
    return 0;
}
