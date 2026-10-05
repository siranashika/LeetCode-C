#include <stdlib.h>
#include <stdbool.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    if (matSize == 0 || matColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matSize;
    int n = matColSize[0];
    int totalElements = m * n;
    *returnSize = totalElements;

    int* result = (int*)malloc(sizeof(int) * totalElements);
    
    int row = 0, col = 0;
    bool directionUp = true;

    for (int i = 0; i < totalElements; i++) {
        result[i] = mat[row][col];

        if (directionUp) {
            if (col == n - 1) {
                row++;
                directionUp = false;
            } else if (row == 0) {
                col++;
                directionUp = false;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == m - 1) {
                col++;
                directionUp = true;
            } else if (col == 0) {
                row++;
                directionUp = true;
            } else {
                row++;
                col--;
            }
        }
    }

    return result;
}
