#include <stdio.h>
#include <ctype.h>

int find_length_str(const char* y);

int main(void){
    char* str = "Hello!"; // lets use char instead of <String.h> library. 
    int length = find_length_str(str);
    printf("Length of string is %d\n", length);
}

int find_length_str(const char* y){
    int counter = 0;
    for(int i = 0; (y[i]) != '\0'; i++){ // works because y is a string of characters or basically a pointer to an array of characters and indexing is dereferencing that pointer y[i] = *(y + i)
        printf(" %c",(y[i]));
        counter++;
    }
    return counter;
}