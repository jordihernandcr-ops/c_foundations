#include <stdio.h>

int get_int(char *);

int main(void){
    int x = get_int("What's x?");
    int y = get_int("What's y?");
    printf("X is: %d\n", x);
    printf("Y is: %d\n", y);
    if(x == y){
        printf("X is equal to Y.\n");
    }else{
        printf("X is not equal to Y.\n");
    }
    return 0;
}

int get_int(char *){
    int mynum =  0;
    scanf("%d", &mynum);
    return mynum;
}