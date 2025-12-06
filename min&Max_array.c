#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    // Read size of the array
    scanf("%d", &n);

    // Edge case: if n <= 0, no elements — you may decide what to do
    if (n <= 0) {
        printf("Array size must be > 0\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minimum = INT_MAX;
    int maximum = INT_MIN;

    // Single pass — O(n) time, O(1) extra space
    for (int i = 0; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    printf("Minimum = %d\n", minimum);
    printf("Maximum = %d\n", maximum);

    return 0;
}

