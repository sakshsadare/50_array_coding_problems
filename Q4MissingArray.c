#include <stdio.h>

int findMissingXOR(int arr[], int n) {
    int xor1 = 0, xor2 = 0;

    // XOR of all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // XOR of all elements in the array
    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;   // This is the missing number
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Missing Number = %d\n", findMissingXOR(arr, n));

    return 0;
}

