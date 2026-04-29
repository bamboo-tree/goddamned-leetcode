#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main() {

  int nums[] = {4,2,1,2,1};
  int size = sizeof(nums)/sizeof(nums[0]);

  int single = singleNumber(nums, size);
  printf("single: %d\n", single);

  return 0;
}

int singleNumber(int* nums, int numsSize) {
  int single = 0;
  for(size_t i = 0; i < numsSize; i++) {
    single ^= nums[i];
  }
  return single;
}