#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int start = 0, end = 0;
    long long sum = 0;
    int found = 0;

    while (end < n) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            // 1-based indexing
            printf("[%d, %d]\n", start + 1, end + 1);
            found = 1;
            break;
        }

        end++;
    }

    if (!found) {
        printf("[-1]\n");
    }

    return 0;
}
