#include <stdio.h>

void find_factors(int n, int i) {
    if (i > n) {
        return;
    }
  
    if (n % i == 0) {
        printf("%d ", i);
    }

    find_factors(n, i + 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
 
    printf("Factors of %d are: ", n);
    find_factors(n, 1);
    printf("\n");
    
    return 0;
}
