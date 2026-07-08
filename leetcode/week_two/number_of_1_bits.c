/*Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
Example 1:
Input: n = 11
Output: 3
Explanation:The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation:The input binary string 1111111111111111111111111111101 has a total of thirty set bits.*/
#include <stdio.h>

int number_of_1_bits(const int num);
bool check_bit(const int num, int i);

int main(void){
    int n = 2147483645;
    int output = number_of_1_bits(n);
    printf("output: %d\n",output);
    return 0;
}

int number_of_1_bits(const int num){
    int value = num;
    int output = 0;
    for(int i = 0; value > 0; i++){
        printf("current value: %d, current output value: %d\n",value, output);
        if(check_bit(value, i)){
            output += 1;
        }
        value = (value & ~(1 << i));
    }
    return output;
}

// Check bit isolates a single bit and checks if it's 0 or 1
bool check_bit(const int num, int i){
    int checker = (1 << i) & num;
    if(checker > 0){
        return true;
    }else{
        return false;
    }
}

/* I quickly realized that my initial implementation was simply finding the total number of bits. instead I should be checking AND then clearing
*/