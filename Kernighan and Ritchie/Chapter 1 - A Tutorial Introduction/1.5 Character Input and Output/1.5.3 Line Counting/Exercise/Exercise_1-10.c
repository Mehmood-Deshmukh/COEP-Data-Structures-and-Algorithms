#include <stdio.h>

int main()
{
    int blanks = 0, tabs = 0, newlines = 0, c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            c = 't';
        }
        if (c == '\b')
        {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\')
        {
            putchar('\\');
            c = '\\';
        }

        putchar(c);
    }
    return 0;
}