#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findPlatform(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);

    int platforms = 1, maxPlat = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        if (platforms > maxPlat)
            maxPlat = platforms;
    }
    return maxPlat;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;

    printf("%d\n", findPlatform(arr, dep, n));
    return 0;
}
