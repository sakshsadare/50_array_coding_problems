#include <stdio.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];  // farthest reachable index
    int step = arr[0];      // steps we can still take
    int jumps = 1;          // at least one jump needed

    for (int i = 1; i < n; i++) {
        if (i == n-1) return jumps;

        // update maxReach
        if (i + arr[i] > maxReach) {
            maxReach = i + arr[i];
        }

        // use a step to move forward
        step--;

        // if no more steps left
        if (step == 0) {
            jumps++;

            // can't move further
            if (i >= maxReach) return -1;

            // re-fill steps for next jump range
            step = maxReach - i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = minJumps(arr, n);

    printf("%d\n", ans);
    return 0;
}

