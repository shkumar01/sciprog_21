/*******************************************************
 *                 Week 7 practical
 *      Exercises with functions using dynamic arrays
********************************************************/

#include <stdio.h>
#include <stdlib.h>

// allocates a contiguous block of memory for an integer array
// of size n
int *allocatearray(int n){
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Array of size %d allocated.\n", n);
    return arr;
}

// sets every element of integer array of size `n` to 1
void fillwithones(int arr[], int n){
    int i;
    for(i=0; i < n; i++){
        arr[i] = 1;
    }
}

// prints the array
void printarray(int *arr, int n) {
    int i;
    for (i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// deallocates the array and frees up the memory
// which can be used by something else
void freearray(int *arr) {
    free(arr);
    printf("Array freed!\n");
    // this doesn't affect the arr variable in the calling code
    // arr here is dummy variable created as a copy
    // arr = NULL;
}

int main() {
    int n;
    int *array_main;

    // User input to set the size of array
    printf("Enter the number of elements in the array: ");
    int err = scanf("%d", &n);

    // Check if scanf was able to read the input entered by the user as an integer
    // or number of elements is negative
    if (err != 1 || n < 0)
    {
        // Invalid input - exit the program
        printf("Bad value\n");
        exit(-1);
    }

    array_main = allocatearray(n);
    fillwithones(array_main, n);
    printarray(array_main, n);
    freearray(array_main);

    // Set the array pointer to NULL to avoid doing anything dangerous with the memory
    // as it still points to the same area which is no longer reserved after freearray
    array_main = NULL;

    return 0;
}
