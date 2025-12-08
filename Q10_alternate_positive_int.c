#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Temporary arrays to store positives and negatives
    int pos[n], neg[n];
    int p = 0, q = 0;

    // Separate positives (including 0) and negatives
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            pos[p++] = arr[i];
        else
            neg[q++] = arr[i];
    }

    int i = 0, ip = 0, in = 0;

    // Merge alternately: positive → negative → positive → negative
    while (ip < p && in < q) {
        arr[i++] = pos[ip++];  // pick positive
        arr[i++] = neg[in++];  // pick negative
    }

    // If positives are left
    while (ip < p) {
        arr[i++] = pos[ip++];
    }

    // If negatives are left
    while (in < q) {
        arr[i++] = neg[in++];
    }

    // Output
    for (int j = 0; j < n; j++)
        printf("%d ", arr[j]);

    return 0;
}
