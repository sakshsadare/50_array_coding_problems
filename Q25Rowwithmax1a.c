#include <stdio.h>

// Function to find the row with the maximum number of 1s
int rowWithMax1s(int mat[][100], int R, int C) {
    int row = 0, col = C - 1;
    int maxRowIndex = -1;

    // Start from top‑right corner
    while (row < R && col >= 0) {
        if (mat[row][col] == 1) {
            maxRowIndex = row;  // update row index
            col--;              // move left
        } else {
            row++;              // move down
        }
    }

    return maxRowIndex;
}

int main() {
    int mat[4][100] = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    int R = 4, C = 4;

    int ans = rowWithMax1s(mat, R, C);
    if (ans != -1)
        printf("%d\n", ans);
    else
        printf("No 1s found\n");

    return 0;
}
