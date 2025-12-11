#include <stdio.h>
#include <stdlib.h>

// comparator for sorting
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minimizeHeights(int arr[], int n, int k) {
    if (n == 1) return 0;  // only one element

    qsort(arr, n, sizeof(int), cmp);

    int ans = arr[n - 1] - arr[0];  // initial gap

    int small = arr[0] + k;
    int big   = arr[n - 1] - k;

    if (small > big) {
        int temp = small;
        small = big;
        big = temp;
    }

    for (int i = 1; i < n - 1; i++) {
        int subtract = arr[i] - k;
        int add      = arr[i] + k;

        // if neither subtract nor add affects the min-max gap
        if (subtract >= small || add <= big)
            continue;

        // adjust either small or big
        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }

    int finalDiff = big - small;
    if (finalDiff < ans)
        ans = finalDiff;

    return ans;
}

int main() {
    int arr[] = {1, 15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    printf("%d\n", minimizeHeights(arr, n, k));
    return 0;
}
