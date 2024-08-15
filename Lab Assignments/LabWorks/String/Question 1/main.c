#include <stdio.h>

#include <stdio.h>

int countNumberOfOcurrences(const char *s, char target);

int main()
{
    const char *s = "Mehmood was here!";
    char target = 'e';
    int count = countNumberOfOcurrences(s, target);

    printf("'%c' occurs %d times in the string \"%s\".\n", target, count, s);

    return 0;
}

int countNumberOfOcurrences(const char *s, char target)
{
    int count = 0;

    while (*s)
    {
        if (*s == target)
        {
            count++;
        }
        s++;
    }

    return count;
}