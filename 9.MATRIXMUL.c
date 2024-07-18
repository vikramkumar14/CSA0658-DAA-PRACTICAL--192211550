#include <stdio.h>

int main() {
    int m, n, p;

    // Get matrix dimensions
    printf("Enter the number of rows in the first matrix (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns in the first matrix (n): ");
    scanf("%d", &n);

    printf("Enter the number of columns in the second matrix (p): ");
    scanf("%d", &p);

    // Validate matrix compatibility for multiplication
    if (n != p) {
        printf("Error: Number of columns in first matrix (n) must equal number of rows in second matrix (p) for multiplication.\n");
        return 1;
    }

    // Explain time complexity (cannot be calculated within the program)
    printf("Time Complexity of Matrix Multiplication:\n");
    printf("The time complexity of multiplying two matrices is O(m * n * p).\n");
    printf("However, this calculation cannot be performed within the program itself.\n");
    printf("The time complexity analysis is based on the number of operations performed during multiplication.\n");
    printf("In this case, for each element in the resulting matrix, there are (n) multiplications and (n - 1) additions.\n");
    printf("The total number of operations is approximately (m * n * p).\n");

    return 0;
}