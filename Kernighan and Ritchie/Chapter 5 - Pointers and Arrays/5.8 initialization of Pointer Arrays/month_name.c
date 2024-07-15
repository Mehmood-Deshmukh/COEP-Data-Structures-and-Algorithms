#include <stdio.h>

char *month_name(int n);
int main() {
    for (int i = 0; i < 13; i++){
        printf("%d. %s\n", i,  month_name(i));
    }
    
    return 0;
}

char *month_name(int n){
    static char *name[] ={
        "Illegal Month",
        "January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}