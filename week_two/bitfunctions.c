/*
Let's assume a hardware register with the following config:
bit 7 | bit 6 | bit 5-4 | bit 3-0
ENABLE| INT_POL| MODE[1:0] | RATE[3:0]
packing means to take individual values and combine them into a single integer -> i.e making mask and shifting them to the left to OR with our register
unpacking = extracting individual values back out from that integer -> i.e masking out bits we want and shifting them right to extract them. 
*/

#include <stdio.h>

void set_bit(int* num, int value, int i);
void clearbits_MSBtoIth_inclusive(int* num, int i);
void clearbits_IthroughLSB(int* num, int i);
void pack_single_bit_register(int* num, int i, int value); 
void pack_multi_bit_register(int* num, int i, int width, int value);
void clear_bit(int* num, int i);
int check_bit(const int num, int i);


int main(void){
    int num = 4;
    int value = 1;
    printf("Original value before cleared bit: %d\n",num);
    clear_bit(&num, 0);
    printf("Value after clearing 0th bit: %d\n",num);
    clear_bit(&num, value);
    printf("Value after clearing 1th bit: %d\n",num);
    set_bit(&num, value, 1);
    printf("Value after setting 1th bit: %d\n",num);
    check_bit(num, 0);
    check_bit(num, 1);
    check_bit(num, 2);
    return 0;
}

/* creates mask by up shifting / left shifting 0 to value we care about. then we AND with our value. 
*/
void clear_bit(int* num, int i){
    int mask = ~(1 << i);
    *num = (*num & mask);
}

/*our implementation is risky because someone may accidentally mess with a separate bit. value parameter SHOULD be masked instead. 
new implementation ensures the value we are passing does not mess with other bits. how I see it:
our mask clears the specific bit we care about. i.e we create a bit mask of say 0100, then we inverse it. this gives us 1011, we can AND this with
our number because it will clear the specific bit without messing with other bits. then, we mask our value by AND it with 1 (0001). This essentially sets it to 1 or 0. 
Then we shift it in place and do an OR. this sets the cleared bit to a 1. 
*/
void set_bit(int* num, int value, int i){
    int mask = ~(1 << i); 
    *num = (*num & mask) | ((value & 1) << i); 
}

/*you should always return a bit otherwise you can't check, initial void implementation was not great for assertions.
instead of shifting a 1 to create a bit mask of say 0100, we simply shift down our bit of interest to the 0th bit then AND with 1.
this solution always gives us a clean 0 or 1 */
int check_bit(const int num, int i){
    return (num >> i) & 1; 
}

/* initial implementation is fine, but it is cleaner to simply do a (num >> i) & 1; this is cleaner.
int output = 1;
output = (1 << i) & num;
printf("output: %d\n",output);
*/

/*clear MSB to 2nd bit if i is 2. which means set them all to 0. essentially if I'm understanding correct, since we are subtracting by -1 we cause cascaded borrows
until we hit the ith-1 position, at this point all remaining values have a 1 because of the binary base 2 borrow mechanic. i.e for example
1 << 4 = 0001 0000 and if we subtract by 1:
        -0000 0001, then we essentially begin the borrowing at the ith bit, the ith bit because 0 and since base 2 creates a 1 in the next place and borrows 1 all the way
        until it can properly subtract by 1. remember, since it borrows and provides a base 2, subtracting by 1 yields a 1 giving us the following answer:
        0000 1111! */
void clearbits_MSBtoIth_inclusive(int *num, int i){
    int mask = ((1 << i) - 1); // sets our mask to all 0's, i exclusive. the neat thing here is that essentiall this clears MSB to i inclusive / sets i-1 bits to 1. 
    *num = (*num & mask);
}

/* -1 = MSB is equal to all 1's (2s complement representation). 
right shifting by i, sets all values until i = 1 since signed bit shift fills shifted bits with MSB sign. 
then we AND with our number to mask. e.g:
    1111. if i = 2, we are essentially shifting all the way until 1 is at the ith + 1 bit, and remaining are 0 (logical shift like we've always been doing)
            then we mask with our number this clears all values from ith to LSB since AND with 0 is 0.
    1000 & 0011 = 1000. NOT INCLUSIVE
*/
void clearbits_IthroughLSB(int *num, int i){
    int mask = ((-1 << i));
    *num = (*num & mask);
}


/* remember we always add our guard. by AND with 1, we essentially mask it so it's all 0's except the LSB. then we shift LSB to corresponding bit value. 
we then OR to set our bit to 1. also, we should always clear bits first too. 
Single bit implementation 
*/
void pack_single_bit_register(int* num, int i, int value){
    int mask = ~(1 << i);
    *num = ((*num & mask) | ((value & 1) << i));
}

/*multi bit implementation
my explanation: we first create a mask to clear the register with respect to it's width. we implement our clear MSB to i trick here to set width number of bits to 1:
we subtract by 1, so the ith bit cascades it's borrow, turning the MSB to ith bit to 0's and i-1 bits to 1s. this should give us an exact width of 1s corresponding to the 
register fields we want to pack. i.e our register is 3 bits wide, so by shifting 1 to the 3rd bit, and subtracting by 1, we get 0-2 bits of 1s (or a width of 3!). from there
we can shift these to the correct position of the register's MSB bit, which we can then clear using the AND operation. from there, our value of interest that has
been safeguarded by ANDing with our mask (makes sure only the correct width of bits are interactd with by zeroing other bits) and shifted into the correct slot using the same ith
value can then be OR'd with our cleared register bits, allowing us to set them without messing with our other bits.*/
void pack_multi_bit_register(int* num, int i, int width, int value){
    int mask = ((1 << width) - 1); 
    int safeguard = value & mask; // CRUCIAL, we need to create our safeguard BEFORE we invert. otherwise we are masking our value with an inverted mask and that ruins things.
    mask = ~(mask << i);
    *num &= mask;
    *num |= (safeguard << i); //CRUCIAL, we AND our value with our mask. this way we safe guard from accidentally setting i through n bits that should be untouched. and maintain the register bit width
}

void pack_multi_bit_register_clean(int* num, int i, int width, int value){
    int field_mask = ((1 << width) - 1); // essentially creates i-1 bits, so if width is 3, we get 0, 1, 2 set bits. total = 3! since it is 0 starting index, and ith gets cleared.
    *num &= ~(field_mask << i); // after our cascaded 1s and cleared MSB to i bits, we can invert this and shift to clear the respective register with correct width
    *num |= ((value & field_mask) << i); // now we can AND our value and field_mask together. doing it this way prevents us from ANDing with wrong field_mask and safeguards by preventing other bits from being accessed by clearing all other bits except the ones we care about. we then shift and OR to set.
}
