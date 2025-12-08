#include <stdio.h>

#define MAX 1000000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Frequency array initialized to 0
    static int freq[MAX + 1] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    int answer = -1;

    // Find first element whose freq > 1
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 1) {
            answer = i + 1;   // 1-based index
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}
