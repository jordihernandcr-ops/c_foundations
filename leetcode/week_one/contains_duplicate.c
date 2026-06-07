// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <stdio.h>

bool containsDuplicate(int* nums, int numsSize);

int main(int argc, char* argv[]){
    int nums[] = {1, 1, 2, 3, 4};
    int nums2[] = {2, 3, 4, 5, 6};
    int numsSizeOne = sizeof(nums) / sizeof(int);
    int numsSizeTwo = sizeof(nums2) / sizeof(int);
    bool value = false;
    value = containsDuplicate(nums, numsSizeOne);
    printf("is duplicate array 1? : %d\n",value);
    value = containsDuplicate(nums2, numsSizeTwo);
    printf("is duplicate array 2? : %d\n",value);
    return 0;
}


bool containsDuplicate(int* nums, int numsSize){
    bool value = false;
    int firstPointer = 1;
    int initialValue = nums[0];
    for(firstPointer; firstPointer < numsSize; firstPointer++){
        printf("current values: %d, %d\n",initialValue, nums[firstPointer]);
        if(nums[firstPointer] == initialValue){

            value = true;
        }else{
            initialValue = nums[firstPointer];
        }
    }
    return value;
}