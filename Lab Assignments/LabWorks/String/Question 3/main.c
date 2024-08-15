#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b);

const char* lcs(const char* s1, const char* s2, int* length);

int main() {
    const char* s1 = "abcdemnopxyz";
    const char* s2 = "mnotq";
    int length;
    const char* subsequence = lcs(s1, s2, &length);

    printf("The Longest Common Subsequence: %s\n", subsequence);
    printf("The Length of LCS: %d\n", length);

    free((void*)subsequence);

    return 0;
}

const char* lcs(const char* s1, const char* s2, int* length) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    int dp[length1 + 1][length2 + 1];

    for (int i = 0; i <= length1; ++i) {
        for (int j = 0; j <= length2; ++j) {
            if (i == 0 || j == 0)
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