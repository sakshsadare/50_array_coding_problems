#include <stdio.h>

int main() {
    int arr[] = {-1, 2, -1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i, j, isRepeat;

    for (i = 0; i < n; i++) {
        isRepeat = 0;

        // check if arr[i] appears again anywhere
        for (j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isRepeat = 1;
                break;
            }
        }

        if (isRepeat == 0) {
            printf("%d\n", arr[i]);
            return 0;
        }
    }

    // If no non-repeating element found
    printf("0\n");
    return 0;
}

