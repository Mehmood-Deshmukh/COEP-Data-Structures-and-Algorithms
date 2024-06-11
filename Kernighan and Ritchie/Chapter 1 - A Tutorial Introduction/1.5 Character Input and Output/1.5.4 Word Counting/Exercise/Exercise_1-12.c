#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, previous, state;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (previous == IN)
                putchar('\n');
        }
        else if (state == OUT)
        {
            putchar(c);
            state = IN;
        }
        else
        {
            putchar(c);
        }

        previous = state;
    }

    return 0;
}