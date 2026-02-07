#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char *argv[]) {

    // initialize method arguments
    int target = 9;
    int nums[] = {2, 7, 13, 9};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize = 0;

    // allocate result memory
    int* result = (int *)malloc(sizeof(int) * 2);
    result = twoSum(nums, numsSize, target, &returnSize);


    printf("result: %d %d (return size: %d)\n", result[0], result[1], returnSize);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize; i++) {
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                *returnSize = 2;
                int* result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;

                return result;
            }
        }
    }

    return NULL;
}
