#include <stdio.h>

int main() {
    int blanks = 0, tabs = 0, newlines = 0, c;
    while ((c = getchar()) != EOF){
        switch (c){
        case ' ':
            ++blanks;
            break;
        case '\t':
            ++tabs;
            break;
        case '\n':
            ++newlines;
            break;
        default:
            break;
        }
    }
    
    printf("There were %d blanks, %d tabs and %d newlines\n", blanks, tabs, newlines);
    return 0;
}