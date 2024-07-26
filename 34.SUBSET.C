#include <stdio.h>

void findSubsetSums(int arr[], int n, int index, int currentSum) {
    if (index == n) {
        printf("%d ", currentSum);
        return;
    }
 
    findSubsetSums(arr, n, index + 1, currentSum + arr[index]);
 
    findSubsetSums(arr, n, index + 1, currentSum);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubsetSums(arr, n, 0, 0);
    
    return 0;
}
