#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (n < 2) {
        printf("[]\n");
        return 0;
    }

    // Sort the array
    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int bestA = INT_MAX, bestB = INT_MAX;
    int minDiff = INT_MAX;       // |sum - target|
    int maxAbsDiff = -1;         // |b - a|

    while (left < right) {
        int sum = arr[left] + arr[right];
        int diff = abs(sum - target);
        int absDiff = arr[right] - arr[left];

        // Check if this pair is better
        if (diff < minDiff ||
           (diff == minDiff && absDiff > maxAbsDiff)) {
            minDiff = diff;
            maxAbsDiff = absDiff;
            bestA = arr[left];
            bestB = arr[right];
        }

        // Move pointers
        if (sum < target)
            left++;
        else
            right--;
    }

    // If no valid pair found
    if (bestA == INT_MAX) {
        printf("[]\n");
    } else {
        printf("[%d, %d]\n", bestA, bestB);
    }

    return 0;
}
