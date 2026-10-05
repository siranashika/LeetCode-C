#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }
    
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = 0;
    int num_k = INT_MIN;
    
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < num_k) {
            free(stack);
            return true;
        }
        while (top > 0 && nums[i] > stack[top - 1]) {
            num_k = stack[--top];
        }
        stack[top++] = nums[i];
    }
    
    free(stack);
    return false;
}
