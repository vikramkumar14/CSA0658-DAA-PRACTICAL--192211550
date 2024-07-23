#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
    if (n <= 2) {
        return (n == 2);
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n, 2)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
