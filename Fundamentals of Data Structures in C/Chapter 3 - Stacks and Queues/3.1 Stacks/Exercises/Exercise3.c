#include <stdio.h>

int fibonacci(int n);

int main() {
    
    return 0;
}

int fibonacci(int n) {
    if (n <= 1){
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
