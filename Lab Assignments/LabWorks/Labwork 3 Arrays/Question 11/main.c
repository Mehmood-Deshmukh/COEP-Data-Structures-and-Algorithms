// Q10. Reverse elements of array without using additional array. 
// Eg 
// input array – {10,45,3216,88} 
// should change to {88,16,32,45,10} 

#include <stdio.h>
void printArray(int arr[], int len);
void reverse(int arr[], int length);

int main() {
    	int arr[] = {11, 23, 31, 11, 43};
    	int length = sizeof(arr) / sizeof(arr[0]);

    	reverse(arr, length);

    	printf("The Reversed array is: ");
		printArray(arr, length);

    	return 0;
}

void printArray(int arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%d", arr[i]);
        } else{
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");
}

void reverse(int arr[], int length) {
    	for (int i = 0; i < length / 2; i++) {
        	int temp = arr[i];
        	arr[i] = arr[length - 1 - i];
        	arr[length - 1 - i] = temp;
    	}
    	return;
}