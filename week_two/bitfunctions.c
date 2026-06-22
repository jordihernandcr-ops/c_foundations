#include <stdio.h>

void clear_bit(int* num, int i);
void set_bit(int* num, int value, int i);

int main(void){
    int num = 2;
    int value = 1;
    printf("Original value before cleared bit: %d\n",num);
    clear_bit(&num, 0);
    printf("Value after clearing 0th bit: %d\n",num);
    clear_bit(&num, value);
    printf("Value after clearing 1th bit: %d\n",num);
    set_bit(&num, value, 1);
    printf("Value after setting 1th bit: %d\n",num);
    return 0;
}

void clear_bit(int* num, int i){
    int mask = ~(1 << i);
    *num = (*num & mask);
}

void set_bit(int* num, int value, int i){
    int mask = ~(1 << i); //to clear it
    *num = (*num & mask) | (value << i); //setting it to value we care about.  
}