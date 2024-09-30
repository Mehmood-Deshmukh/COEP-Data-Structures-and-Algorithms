/* 
4 Convert a base 10 integer value to base 2
*/


/* To solve this problem we will be using an integer stack*/
#include "../Character Stack Implementation Using Singly LinkedList/logic.c"

/* Our approach for solving this problem is as follows:
We will use the property of the binary number system that a number can be represented as a sum of powers of 2.
For example, 13 can be represented as 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0 = 1101
So to convert a number to binary we will:
1. We will keep dividing the number by 2 and push the remainder onto the stack.
2. After dividing the number by 2 we will pop the elements from the stack and form the binary number.
3. we also need to handle the case when the number is negative
*/
char *decimalToBinary(int num);

int main(){
    int num;
    printf("Enter a base 10 number: ");
    scanf("%d", &num);

    printf("The base 2 representation of %d is: %s\n", num, decimalToBinary(num));
    return 0;
}

/*
we will solve this problem using the approach mentioned above.
*/
char *decimalToBinary(int num){
    cStack s;
    cinit(&s);
    unsigned int unsignedNum;

    if(num < 0){
        unsignedNum = (unsigned int)(-num);
        unsignedNum = ~unsignedNum + 1;
    }else{
        unsignedNum = num;
    }

    if(unsignedNum == 0){
        cpush(&s, '0');
    }

    while(unsignedNum > 0){
        cpush(&s, unsignedNum % 2 + '0');
        unsignedNum /= 2;
    }

    char *binary = (char *)malloc(sizeof(char) * 33);
    if(!binary) return NULL;

    int i = 0;
    while(!cisEmpty(s)){
        binary[i++] = cpop(&s);
    }
    binary[i] = '\0';

    return binary;
}

