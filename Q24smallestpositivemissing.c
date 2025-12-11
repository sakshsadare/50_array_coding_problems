#include <stdio.h>
#include <stdlib.h>

// Function to find the smallest positive missing number
int missingNumber(int arr[], int n) {
    // Step 1: Replace non-positive and out‑of‑range values with n+1
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0 || arr[i] > n)
            arr[i] = n + 1;
    }

    // Step 2: Mark presence of values 1..n by negating at index (val - 1)
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        if (val <= n) {
            if (arr[val - 1] > 0)
                arr[val - 1] = -arr[val - 1];
        }
    }

    // Step 3: First positive index + 1 is the answer
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            return i + 1;

    // If all 1..n are present
    return n + 1;
}
