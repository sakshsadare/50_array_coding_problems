#include <stdio.h>

void rotateByOne(int arr[], int n) {
    if (n <= 1) return;

    int last = arr[n-1];
    for (int i = n-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rotateByOne(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

