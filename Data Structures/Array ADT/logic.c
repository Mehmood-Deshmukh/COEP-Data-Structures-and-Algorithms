#include "./header.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void init(Array *a, int size){
    a->A = (int *)malloc(sizeof(int) * size);
    if(!a->A) return;

    a->size = size;
    a->len = 0;
}

void append(Array *a, int element){
    if(a->len ==  a->size) return;

    a->A[a->len++] = element;
    return;
}

void insertAtIndex(Array *a, int element, int position){
    int length = a->len;
    if (length == a->size || position < 0 || position >= length) return;

    for(int i = length; i >= position; i--){
        a->A[i] = a->A[i - 1];
    }

    a->A[position] = element;
    a->len++;
    return;
}

int removeAtIndex(Array *a, int position){
    int length = a->len;
    if (position < 0 || position >= length) return INT_MIN;

    int removedElement = a->A[position];
    for(int i = position + 1; i < length; i++){
        a->A[i - 1] = a->A[i];
    }
    a->len--;
    return removedElement;    
}

void display(Array a){
    int length = a.len;

    printf("Displaying Array: [");

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", a.A[i]);
    }

    printf("\b\b]\n");
    return;    
}

int max(Array a){
    if(a.len == 0) return INT_MIN;
    int maxElement = a.A[0], length = a.len;

    for(int i = 1; i < length; i++){
        int currentElement = a.A[i];
        if(currentElement > maxElement) maxElement = currentElement;
    }
    return maxElement; 
}
int min(Array a){
    if(a.len == 0) return INT_MAX;
    int minElement = a.A[0], length = a.len;

    for(int i = 1; i < length; i++){
        int currentElement = a.A[i];
        if(currentElement < minElement) minElement = currentElement;
    }
    return minElement; 
}


Array merge(Array a1, Array a2){
    Array merged;
    int length1 = a1.len , length2 = a2.len;
    init(&merged, length1 + length2);
    for(int i = 0; i < length1; i++){
        append(&merged, a1.A[i]);
    }

    for(int i = 0; i < length2; i++){
        append(&merged, a2.A[i]);
    }

    return merged;
}

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

void fill(Array *a){
    int length = a->len;

    for (int i = length; i < a->size; i++){
        a->A[i] = rand() % 100;
    }

    a->len = a->size;
    return;  
}

void reverse(Array *a){
    int length = a->len, temp;
    for(int i = 0; i < length/2; i++){
        temp = a->A[i];
        a->A[i] = a->A[length - i - 1];
        a->A[length - i - 1] = temp;
    }

    return;
}