#include <stdio.h>

int main()
{
    int blanks = 0, tabs = 0, newlines = 0, c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') {
            putchar(c);
            while ((c = getchar()) == ' ');
        }
        
        putchar(c);
    }
    return 0;
}