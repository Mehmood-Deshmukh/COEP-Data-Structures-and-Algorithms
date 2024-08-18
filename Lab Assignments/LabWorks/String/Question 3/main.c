#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//this is a MACRO to get MAX of two values
#define MAX(a, b) ((a) > (b)) ? (a) : (b);

// function prototype
char* lcs(char* s1, char* s2, int* length);

int main() {
    char* s1 = "abcdemnopxyz"; //this is the string in which we will search for the longest subsequence
    char* s2 = "mnotq"; // we have to find the longest subsequence of this string

    int length; // this will store the length of the longest subsequence
    char* subsequence = lcs(s1, s2, &length); //get the lCS

    printf("The Longest Common Subsequence: %s\n", subsequence);
    printf("The Length of LCS: %d\n", length);

    free((void*)subsequence);

    return 0;
}

// initially i had written a function using recursion which was very inefficient and hence i took reference from the internet where i got to know about the dunamic programming solution

//  here is the old solution:
// int lcs(char* s1, char* s2) {
//     if(*s1 == '\0' || *s2 == '\0') return 0;

//     if(*s1 == *s2) return 1 + lcs(s1 + 1, s2 + 1);

//     return MAX(lcs(s1 + 1, s2), lcs(s1, s2 + 1));

// }

// here is the dp solution
char* lcs(char* s1, char* s2, int* length) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    int dp[length1 + 1][length2 + 1]; //initailize a 2d array

    for (int i = 0; i <= length1; ++i) {
        for (int j = 0; j <= length2; ++j) {
            if (i == 0 || j == 0) //if any of the strings length is 0 answer will be 0
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    *length = dp[length1][length2];

    char* subsequence = (char*)malloc((*length + 1) * sizeof(char));

    int i = length1, j = length2, index = *length;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            subsequence[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    subsequence[*length] = '\0';

    return subsequence;
}