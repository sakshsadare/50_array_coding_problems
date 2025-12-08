#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findPairs(int arr[], int n) {

    qsort(arr, n, sizeof(int), cmp);  // step 1: sort

    int i = 0, j = n - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == 0) {
            printf("[%d, %d]\n", arr[i], arr[j]);

            int a = arr[i], b = arr[j];

            // skip duplicates
            while (i < j && arr[i] == a) i++;
            while (i < j && arr[j] == b) j--;
        }
        else if (sum < 0) {
            i++;  // need bigger number
        }
        else {
            j--;  // need smaller number
        }
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairs(arr, n);

    return 0;
}

