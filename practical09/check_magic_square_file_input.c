/*******************************************************
 *                 Week 9 practical
 *           Magic Squares - Input from file
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

// constant defining the maximum size of a file name
// pre-processor replaces MAX_FILE_NAME with 100 everywhere it finds it in code
#define MAX_FILE_NAME 100

/* Function prototypes */

// Get total number of lines given file
int getlines(char filename[MAX_FILE_NAME]);

int main() {

    FILE *f;
    char filename[MAX_FILE_NAME];

    // Get user input for filename
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file in reading mode
    f = fopen(filename, "r");

    int n = getlines(filename);

    // Allocate a matrix of size nxn same as in usr_input version of this
    int i;
    int ** magicSquare = (int **) malloc(n * sizeof(int*));

    for(i = 0; i < n; i++) {
        magicSquare[i] = (int *) malloc(n*sizeof(int));
    }

    // Read in values from the file
    int j;
    for(i = 0; i < n; i++) {
        for(j=0; j<n; j++) {
            // columns are seperated by whitesapce
            fscanf(f,"%d", &magicSquare[i][j]);
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

    // Close the handle to the file
    fclose(f);

    return 0;
}

// Get total number of lines given file
int getlines(char filename[MAX_FILE_NAME]) {

    FILE *fp;
    // Open the file in reading mode
    fp = fopen(filename, "r");

    int ch_read; // Shouldn't this be a char? I guess it doesn't matter since they can be converted
                 // or casted to one another
    int count = 0;
    // fgetc gets a single character from file and moves up to next character
    // We count the number of new line characters in the file
    while ((ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. of lines %d\n", count);

    // Close the file after we open it
    fclose(fp);
    return count;
}