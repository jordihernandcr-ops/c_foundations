/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
*/

/* RED: Needed several hints even after remembering some of the solution. Intuition was shakey, two different solutions and I mixed them up on initial try. 
// answer why doing XOR of sums gives us the missing number m (where y and x are the sum of the respective truth and provided arrays): m⊕y=x, since y⊕y = 0, if we 
do some algebra and perform the XOR of y to both sides to cancel out aka self-inversing, m⊕y⊕y = x⊕y then, solving gives us m = x⊕y.  
but why does the sum of XORs work then? because of the fact that XOR is self-inversing, commutative, AND associative its commutative monoid(or group) as in:

If you have a big pile of items to combine with such an operation, you can split the pile into any sub-piles you like, reduce each sub-pile independently, 
and then combine those partial results — and you're guaranteed to get the exact same answer as if you'd reduced the whole pile in one pass, in any order.

PATTERN: XOR cancels matching pairs, isolates unamtched - for this problem : matched against a generated range, 

/
int missingNumber(int* nums, int numsSize);
int missingNumberXOR(int* nums, int numsSize);

#include <stdio.h>


int main(int argc, char *argv[]){
    int nums[] = {0,1,3,2};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    //int x = missingNumber(nums, 3);
    int y = missingNumberXOR(nums, 4);
    printf("Missing number: %d\n",y);
}

int missingNumber(int* nums, int numsSize) {
    int temp[numsSize+1];
    int sum = numsSize;
    int sum_two = 0;
    for(int i = 0; i < numsSize; i++){
        sum = sum + i;
        sum_two = sum_two + nums[i];
        printf("sum %d, sum_two: %d\n",sum,sum_two);
    }
    printf("sum %d, sum_two: %d\n",sum,sum_two);
    return (sum - sum_two);
}

int missingNumberXOR(int* nums, int numsSize){
    int running_total = numsSize;
    for(int i = 0; i < numsSize; i++){
        running_total = running_total ^ i ^ nums[i];
    }
    return running_total;
}