#include <stdio.h>

int lower(int c);

int main() {
    printf("%c", lower('A'));
    return 0;
}

int lower(int c){
    if (c > 'A' && c < 'Z'){
        printf("upper");
        return c + 'a' - 'A';
    }else{
        return c;
    }
    
}