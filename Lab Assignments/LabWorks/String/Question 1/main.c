// Write a function to count number of occurrences of a character in a string;

#include <stdio.h>

#include <stdio.h>

// function prototype
int countNumberOfOcurrences(char *s, char target);

int main()
{
    char *s = "Mehmood was here!"; //this is the input string
    char target = 'e'; // this is the target

    int count = countNumberOfOcurrences(s, target);

    printf("'%c' occurs %d times in the string \"%s\".\n", target, count, s);

    return 0;
}


// the function return the number of occurrences of target in string s
int countNumberOfOcurrences(char *s, char target)
{
    int count = 0; // initialzing the count to 0

    while (*s)  // traverse through each character of string 
    {
        if (*s == target) // if the  current character matches target increment the count
        {
            count++;
        }
        s++;
    }

    return count; // return the final count
}