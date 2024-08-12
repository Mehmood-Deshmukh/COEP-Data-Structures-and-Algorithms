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

void printMenu(){
    printf("\n\n***********Array ADT Menu:***********\n\n");
    printf("Select any of the instructions given below:\n");
    printf("1. Initialize a new Array.\n");
    printf("2. Append an element to an existing Array.\n");
    printf("3. Insert element at a given index.\n");
    printf("4. Remove element at a given index.\n");
    printf("5. Display an Array.\n");
    printf("6. Display the maximum element in an Array.\n");
    printf("7. Display the minimum element in an Array.\n");
    printf("8. Reverse an Array.\n");
    printf("9. Merge two Arrays.\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

void handleChoice(int choice, Array *array){
    switch (choice) {
        case 1: {
            int size;
            printf("\nEnter the size of the Array: ");
            scanf("%d", &size);
            init(array, size);
            printf("\nArray initialized with size %d.\n", size);
            break;
        }
        case 2: {
            int element;
            printf("\nEnter the element to append to the Array: ");
            scanf("%d", &element);
            append(array, element);
            printf("\nElement appended to array : %d.\n", element);
            break;
        }
        case 3: {
            int element, index;
            printf("\nEnter the element to add to the Array: ");
            scanf("%d", &element);
            printf("\nEnter the index at which the element is to be added: ");
            scanf("%d", &index);
            insertAtIndex(array, element, index);
            printf("\nElement %d inserted at index %d.\n", element, index);
            break;
        }
        case 4: {
            int index;
            printf("\nEnter the index at which the element is to be removed: ");
            scanf("%d", &index);
            int removedElement = removeAtIndex(array, index);
            printf("\nRemoved Element: %d\n", removedElement);
            break;
        }
        case 5: {
            display(*array);
            break;
        }
        case 6: {
            int maxElement = max(*array);
            printf("\nMaximum element in the Array: %d\n", maxElement);
            break;
        }
        case 7: {
            int minElement = min(*array);
            printf("\nMinimum element in the Array: %d\n", minElement);
            break;
        }
        case 8: {
            reverse(array);
            printf("\nArray reversed.\n");
            break;
        }
        case 9: {
            Array array2, mergedArray;
            int size;
            printf("\nEnter the size of the second Array: ");
            scanf("%d", &size);
            init(&array2, size);
            printf("\nFilling the second Array.\n");
            fill(&array2);
            mergedArray = merge(*array, array2);
            printf("Arrays merged.\n");
            display(mergedArray);
            break;
        }
        case 10:
            printf("\nExiting....\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}