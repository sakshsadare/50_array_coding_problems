// Problem: Array Subset of Another Array
// Link: https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Approach: Sorting + Two Pointers
// Time: O(m log m + n log n), Space: O(1)
// Author: Sakshi Sadare

#include <stdio.h>

// Simple quicksort implementation
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Function to check if B[] is subset of A[]
int isSubset(int A[], int m, int B[], int n) {
    // Step 1: sort both arrays
    quickSort(A, 0, m - 1);
    quickSort(B, 0, n - 1);

    // Step 2: two-pointer technique
    int i = 0, j = 0;

    while(i < m && j < n) {
        if(A[i] < B[j]) {
            i++;
        }
        else if(A[i] == B[j]) {
            i++;
            j++;   // match found
        }
        else {
            return 0;  // A[i] > B[j] → missing element
        }
    }

    // If B is fully traversed → it's a subset
    return (j == n);
}

int main() {
    int A[] = {11, 1, 13, 21, 3, 7};
    int B[] = {11, 3, 7, 1};

    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);

    if(isSubset(A, m, B, n))
        printf("Yes, B is subset of A\n");
    else
        printf("No, B is not subset of A\n");

    return 0;
}

