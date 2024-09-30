/* 
4 Convert a base 10 integer value to base 2
*/

#include "../Stack Implementation Using Singly LinkedList/logic.c"

int decimalToBinary(int num);

int main(){
    int num;
    printf("Enter a base 10 number: ");
    scanf("%d", &num);

    printf("The base 2 representation of %d is: %d\n", num, decimalToBinary(num));
    return 0;
}

int decimalToBinary(int num){
    Stack s;
    init(&s);
    while(num){
        push(&s, num % 2);
        num /= 2;
    }

    int binary = 0;
    while(!isEmpty(s)){
        binary = binary * 10 + pop(&s);
    }

    return binary;
}

