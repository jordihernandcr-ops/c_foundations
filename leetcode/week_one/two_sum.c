// Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

// Return the answer with the smaller index first.

// Input: 
// nums = [3,4,5,6], target = 7
// Output: [0,1]

// constraints:
// 2 <= nums.length <= 1000
// -10,000,000 <= nums[i] <= 10,000,000
// -10,000,000 <= target <= 10,000,000
// Only one valid answer exists.


// perhaps you can sort first, then use the largest number and and if the remainder exists in the second half, you can avoid searching through the entire list again and again
// naive / brute force approach and does not properly take into account edge cases
//proper solution involves hash map, color: YELLOW - revisit once touched hash maps for complements
#include <stdio.h>

int main(int argc, char* argv[]){
    int target = 10;
    int nums[] = {3,4,5,6};
    int index_one = 0;
    int index_two = 2;
    int sizeof_nums = sizeof(nums) / sizeof(int);
    for(int i = 0; i < sizeof_nums; i++){
        index_one = i;
        int remainder = target - nums[i];
        for(int j = 1; j < sizeof_nums; j++){
            if (nums[j] = remainder){ // was originally returning j and not the index
                index_two = j; 
                break;
            }
        }
    }
    printf("Solution pair: {%d, %d}\n",index_one,index_two);
    return 0;
}