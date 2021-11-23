/*******************************************************
 *                 Week 9 practical
 *           Magic Squares - User Input
********************************************************/

#include <stdio.h>
#include <stdlib.h>
// include the file magic_square.h from current directory
// "" vs <>
// The file contains the isMagicSquare function which checks if a given
// 2d matrix is a magic square
#include "magic_square.h"

int main() {

    int n;

    // Get user input
    printf("Enter the square side:\n");
    int err = scanf("%d", &n);

    // Validate input
    if (err != 1 || n <= 0) {
        printf("Invalid input, please try again\n");
    }

    // Allocate a matrix of size nxn
    int i;
    // Pointer to a pointer i.e an array of pointers
    int ** magicSquare = (int **) malloc(n * sizeof(int *));
    // For each pointer in array of pointers we allocate and integer array of size n
    for(i = 0; i < n; i++) {
        magicSquare[i] = (int *) malloc(n*sizeof(int));
    }

    // Get user input
    int j;
    for(i = 0; i < n; i++) {
        // Read in row
        printf("Enter the element in row #%d, separated by blanks and/or linebreaks:\n", i+1);
        for(j=0; j<n; j++) {
            // Each column
            scanf("%d", &magicSquare[i][j]);
        }
    }

    // Ternary operator - avoids having to do if/else
    // print out if square is magic or not
    printf("The square %s magic.\n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");

    // Free all the memory we've allocated for each pointer in the array of pointers
    for(i=0; i < n; i++) {
        free(magicSquare[i]);
        magicSquare[i] = NULL;
    }
    // Free all the memory we've allocated for the pointer pointing to the array of pointers
    free(magicSquare);
    magicSquare = NULL;

    return 0;
}
