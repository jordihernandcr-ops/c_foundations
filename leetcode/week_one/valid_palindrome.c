// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
//removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

//initial issue: I used pointer to initiate array. Of course an array decays to a pointer to it's initial variable but we are using wrong syntax. 
//better mental model:
// Array:
// A real block of memory containing elements.

// Pointer:
// A variable that stores the address of something.

// Array decay:
// In many expressions, the array's name behaves like a pointer to its first element. i.e nums[i] is actually *(nums + i) where we do pointer arithmetic on the pointer referencing the initial element of the arr

//sizeof sees the whole array

//thus sizeof char* palindrome, only gets the size of the pointer which is always 8 bytes on a 64 bit machine. we need to allocate the array properly instead to avoid this issue



#include <stdio.h>

bool valid_palindrome(const char *s, const int stringLength);


int main(int argc, char* argv[]){
    char palindrome[] = {"ca"}; // WRONG WAY TO DO IT. This returns the size of the pointer, since this is 8 bytes it will always return 8. 
    int sizeof_palindrome = sizeof(palindrome) / sizeof(char);
    bool palindrome_truefalse = false;
    printf("Size of string: %d\n",sizeof_palindrome);
    if(sizeof_palindrome < 3){
        printf("Not a palindrome\n");
        return 0;
    }
    palindrome_truefalse = valid_palindrome(palindrome, sizeof_palindrome);
    printf("Palindrome?: %d\n",palindrome_truefalse);
    return 0;
}

// let me think.. racecar\0 is 8 characters, localStringIterator is 7, we need to remove 2 because string length starts at 0 index
// so to access the final value of a string, we need to do stringLength - 2!
bool valid_palindrome(const char *s, const int stringLength){
    char localString[210];
    int localStringIterator = 0;
    bool palindrome = true;
    for(int i = 0; i < stringLength; i++){
        // remove white length 
        if ((s[i]) != ' '){
            localString[localStringIterator] = (s[i]);
            localStringIterator++;
            printf("%d\n",localStringIterator);
        }
    }
    //now we implement the two pointers, one accessing the first and one accessing the last and they continue 
    //towards the middle and if each element is equal along the way we are good as a palindrome
    int k = localStringIterator - 2;
    printf("Value of k: %d\n",k);
    for(int j = 0; j < stringLength; j++){
        printf("Current check: %c, %c\n",localString[j],localString[k]);
        if(localString[j] != localString[k]){
            palindrome = false;
        }else{
            k--;
        }
    }
    return palindrome;
}