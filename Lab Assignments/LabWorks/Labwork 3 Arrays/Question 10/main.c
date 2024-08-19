/*
Q 10. Write a program to check if elements of an array are the same when read from front or back. (Palindrome)
Example: 2 3 15 15 3 2
*/

#include <stdio.h>

int isPalindrome(int arr[], int len);
int main() {
    	int arr[] = {2, 3, 15, 11, 3, 2};
    	int len = sizeof(arr) / sizeof(arr[0]);

    	if (isPalindrome(arr, len)){
            printf("Elements of the array are the same from front to back.\n");
        } else {
            printf("Elements of the array are not the same from front to back.\n");
        }

    	return 0;
}


int isPalindrome(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        if (arr[i] != arr[len - 1 - i]) {
            return 0; 
        }
    }
    return 1;
}

