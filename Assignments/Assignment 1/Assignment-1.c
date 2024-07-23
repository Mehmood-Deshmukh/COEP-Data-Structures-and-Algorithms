#include "./logic.c"

int main(){
    int len = 8;
    printf("Enter the length of Array: ");
    scanf("%d", &len);

    printf("Your length is: %d\n", len);

    double arr[len];
    for(int i = 0; i < len; i++){
        scanf("%lf", &arr[i]);
    }

    printf("Your Array is: ");
    printArray(arr, len);


    removeDuplicates(arr, &len);

    printf("The new Array is: ");
    printArray(arr, len);


    return 0;
}