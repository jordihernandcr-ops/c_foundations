/* 
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

YELLOW: Intuitively solved after spending half an hour on missing number problem. However, I'm sure reviewing will help.
PATTERN: XOR cancels matching pairs, isolates unamtched - for this problem : matched within array itself
*/
#include <stdio.h>

int singleNumber(int *nums, int numsSize);

int main(void){
    int nums[] = {4,1,2,1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int x = singleNumber(nums, numsSize);
    printf("missing_number: %d\n", x);
    return 0;
}


int singleNumber(int *nums, int numsSize){
    int single_number = 0;
    for(int i = 0; i < numsSize; i++){
        single_number = single_number ^ nums[i];
    }
    return single_number;
}