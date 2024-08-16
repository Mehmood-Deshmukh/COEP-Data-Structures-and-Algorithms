// 2. Write a C program to check whether a number is negative, positive or zero. 

#include <stdio.h>
int getSign(int num);
int main() {
    int num = 0;
    char *options[] = {"Zero", "Positive", "Negative"};
    printf("The numbers is %s\n",  options[getSign(num)]);
    return 0;
}
int getSign(int num){
    if(num == 0){
        return 0;
    }else if(num > 0){
        return 1;
    }else{
        return 2;
    }
}