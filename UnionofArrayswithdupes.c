#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void printUnion(int a[], int n, int b[], int m) {
    int size = n + m;

    int arr[size];

    // copy both arrays into one
    for (int i = 0; i < n; i++) arr[i] = a[i];
    for (int i = 0; i < m; i++) arr[n + i] = b[i];

    // sort the combined array
    qsort(arr, size, sizeof(int), cmp);

    // print distinct elements only once
    printf("Union: ");
    printf("%d ", arr[0]);   // print first element

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 2, 1};
    int b[] = {3, 2, 2, 3, 3, 2};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    printUnion(a, n, b, m);

    return 0;
}
