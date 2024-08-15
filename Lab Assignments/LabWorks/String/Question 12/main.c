#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main() {
    char str[] = "Mehmood";

    printf("The Reverse Representation of %s is ", str);
    reverseString(str);
    printf("%s\n", str);
    
    return 0;
}

void reverseString(char *str){
    int len = strlen(str);

    for(int i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
