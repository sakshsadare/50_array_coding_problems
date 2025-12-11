#include <stdio.h>
#include <stdlib.h>

// Function to check if a triplet with given sum exists
int find3Sum(int arr[], int n, int target) {
    // sort array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // check for triplet
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target)
                return 1;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    return 0;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int target = 13;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (find3Sum(arr, n, target))
        printf("Yes, a triplet exists\n");
    else
        printf("No triplet found\n");

    return 0;
}
