#include <stdio.h>

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = arr[0];
    int curr_sum = arr[0];

    for (int i = 1; i < n; i++) {
        // Either extend the current subarray or start new from arr[i]
        if (curr_sum + arr[i] > arr[i])
            curr_sum = curr_sum + arr[i];
        else
            curr_sum = arr[i];

        // Update global max
        if (curr_sum > max_sum)
            max_sum = curr_sum;
    }

    printf("%d\n", max_sum);
    return 0;
}
