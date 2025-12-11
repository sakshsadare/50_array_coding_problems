#include <stdio.h>

int findPeak(int arr[], int n) {
    if (n == 1) return 0;  // only one element → peak

    // check first element
    if (arr[0] >= arr[1]) return 0;

    // check last element
    if (arr[n-1] >= arr[n-2]) return n-1;

    // check internal elements
    for (int i = 1; i < n-1; i++) {
        if (arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) {
            return i;
        }
    }
    return -1;  // should never happen
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeak(arr, n);

    if (peakIndex != -1)
        printf("%d\n", arr[peakIndex]);
    else
        printf("-1\n");

    return 0;
}
