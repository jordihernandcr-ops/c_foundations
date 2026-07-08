/* Reverse bits of a given 32 bits signed integer. 
constraints: 0 <= n <= 2^31-2
n is even Input: n = 43261596
Output: 964176192*/
#include <stdint.h>
#include <stdio.h>


uint32_t reverseBits(uint32_t n);



int main(int argc, char* argv[]){
    //int input = 43261596;
    //reverseBits(&input);
    uint32_t input = 43261596;
    uint32_t output = reverseBits(input);
    printf("value after reverse bits: %d\n",output);
    return 0;
}



uint32_t reverseBits(uint32_t n) {
    uint32_t num = n;
    uint32_t temp = 0;
    uint32_t count = 31;
    for(int i = 0; i < 32; i++){
        uint32_t value = (num >> count) & 1;
        temp = temp | (value << i); 
        count = count - 1;
    }
    return temp;
}
