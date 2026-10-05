#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    int totalElements = m * n;
    *returnSize = totalElements;

    int* result = (int*)malloc(sizeof(int) * totalElements);
    int count = 0;

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[count++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[count++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[count++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[count++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}
