#include <stdio.h>

void spiralPrint(int mat[][100], int r, int c) {
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        // Print top row (left → right)
        for (int j = left; j <= right; j++)
            printf("%d ", mat[top][j]);
        top++;

        // Print right column (top → bottom)
        for (int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        // Print bottom row (right → left) if still valid
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", mat[bottom][j]);
            bottom--;
        }

        // Print left column (bottom → top) if still valid
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }
}

int main() {
    int mat[100][100];
    int r, c;

    // Read rows and columns
    scanf("%d %d", &r, &c);

    // Read matrix
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    // Print spiral
    spiralPrint(mat, r, c);

    return 0;
}
