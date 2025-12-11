#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int kthSmallest(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmp);
    return arr[k - 1];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = kthSmallest(arr, n, k);
    printf("%d\n", result);

    return 0;
}
