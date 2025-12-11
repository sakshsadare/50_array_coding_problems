#include <stdio.h>

int maxProduct(int arr[], int n) {
    if (n == 0) return 0;

    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        int val = arr[i];

        if (val < 0) {
            // swap max and min if negative
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }

        // update maxProd and minProd
        if (maxProd * val > val)
            maxProd = maxProd * val;
        else
            maxProd = val;

        if (minProd * val < val)
            minProd = minProd * val;
        else
            minProd = val;

        if (maxProd > result)
            result = maxProd;
    }

    return result;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxProduct(arr, n));
    return 0;
}
