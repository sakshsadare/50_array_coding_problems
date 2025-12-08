#include<stdio.h>
voidfindTwoElements(int arr[], int n, int result[])
{ int freq[n+1];

for int(i=0;i<=n;i++)
  {
    freq[i] = 0;
}
int duplicate = -1, missing = -1;
for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] == 2) {
            duplicate = arr[i];
        }
    }

    // Find missing number
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            missing = i;
            break;
        }
    }

    result[0] = duplicate;
    result[1] = missing;
}
int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[2];

    findTwoElements(arr, n, result);

    printf("Duplicate: %d\n", result[0]);
    printf("Missing : %d\n", result[1]);

    return 0;
}

