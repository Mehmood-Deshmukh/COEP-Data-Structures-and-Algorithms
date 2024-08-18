#include "./header.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//function to initialize the array
void init(Array *a, int size){
    a->A = (int *)malloc(sizeof(int) * size); //allocate memory
    if(!a->A) return; // if memory allocation fails, return 

    a->size = size; //set size
    a->len = 0;
}

//function to append an element to array
void append(Array *a, int element){
    if(a->len ==  a->size) return; //if array is full return 

    a->A[a->len++] = element; // append element
    return;
}

// function to insert an element at a particular index
void insertAtIndex(Array *a, int element, int position){
    int length = a->len;
    // if the index is invalid or if the array is full return 
    if (length == a->size || position < 0 || position > length) return; 

    // shift elements to the next index
    for(int i = length; i >= position; i--){
        a->A[i] = a->A[i - 1];
    }

    // add element at index
    a->A[position] = element;
    a->len++; //increment the length
    return;
}

// function to remove element at a particular index
int removeAtIndex(Array *a, int position){
    int length = a->len;
    // if the index is invalid return 
    if (position < 0 || position >= length) return INT_MIN;

    // store the element to remove as we will return it
    int removedElement = a->A[position];

    // shift elements after the index to one position back
    for(int i = position + 1; i < length; i++){
        a->A[i - 1] = a->A[i];
    }
    a->len--; //decrement the length
    return removedElement; //return the removed element
}

// function to display the array
void display(Array a){
    int length = a.len;
    // if array is empty return 
    if(length == 0){
        printf("Array is empty!");
        return;
    }

    printf("Displaying Array: [");

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", a.A[i]);
    }

    printf("\b\b]\n"); //remove the ending comma
    return;    
}


// function to get the maximum element
int max(Array a){
    // if array is empty return 
    if(a.len == 0) return INT_MIN;
    int maxElement = a.A[0], length = a.len;

    // traverse through entire array and check for the maximum element
    for(int i = 1; i < length; i++){
        int currentElement = a.A[i];
        if(currentElement > maxElement) maxElement = currentElement;
    }
    return maxElement; 
}

// function to get the minimum element
int min(Array a){
    // if array is empty return 
    if(a.len == 0) return INT_MAX;
    int minElement = a.A[0], length = a.len;

    // traverse through entire array and check for the minimum element
    for(int i = 1; i < length; i++){
        int currentElement = a.A[i];
        if(currentElement < minElement) minElement = currentElement;
    }
    return minElement; 
}

// function to merge two arrays
Array merge(Array a1, Array a2){
    Array merged; //create a new array
    int length1 = a1.len , length2 = a2.len;
    init(&merged, length1 + length2); // initialze the new array with length = length1 + length2
    
    //append elements of first array
    for(int i = 0; i < length1; i++){
        append(&merged, a1.A[i]);
    }

    //append elements of second array
    for(int i = 0; i < length2; i++){
        append(&merged, a2.A[i]);
    }

    return merged;
}

//simple selection sort algorithm

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void sort(Array *a){
    int length = a->len;
    int i, j, min;
    for(i = 0; i < length - 1; i++){
        min = i;
        for(j = i + 1; j < length; j++){
            if(a->A[j] < a->A[min]) min = j;
        }
        swap(&a->A[i], &a->A[min]);
    }
}

// function to fill array with random elements
void fill(Array *a){
    int length = a->len;

    for (int i = length; i < a->size; i++){
        a->A[i] = rand() % 100; // random number from 0 - 99
    }

    a->len = a->size;
    return;  
}

// function to reverse an array
void reverse(Array *a){
    int length = a->len, temp;
    for(int i = 0; i < length/2; i++){
        temp = a->A[i];
        a->A[i] = a->A[length - i - 1];
        a->A[length - i - 1] = temp;
    }

    return;
}
