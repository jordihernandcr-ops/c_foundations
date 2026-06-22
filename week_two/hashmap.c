/* Hash maps are typically of the following nature:
1) create hash function
2) create hash per string
3) correlate hash to specific array index
4) place hash string pair in linked list node at array index

return when linked list refresher is done*/

#include <stdio.h>

unsigned long hash(unsigned char *str);

int main(int argc, char* argv){



    return 0;
}

// djb2 hash function for string hashing
unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;

    // not sure what this equal statement is checking, while c is equal to a str pointer? and then increment it?
    while ((c = *str++)){ 
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}