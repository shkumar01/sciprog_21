/*******************************************************
 *                 Week 6 practical
 *               Matrix Multiplication
********************************************************/

#include <stdio.h>

/* Function prototypes */

// prints a matrix somewhat nicely given it's size nxm
void print_matrix(int n, int m, double M[n][m]);

int main() {

    // Create the matrix's
    // told size of matrices is 5x3 3x4
    // -> size of product matrix is 5x4
    int n=5, p=3, q=4;
    double A[n][p], B[p][q], C[n][q];
    int i, j ,k;

    /* Initialize A, B and C matrices */

    // Set all elements of C to 0.0
    for (i=0; i<n; i++) {
        for (j=0; j<q; j++) {
            C[i][j] = 0.0;
        }
    }
    // Set every element A[i][j] to i+j
    for (i=0; i<n; i++) {
        for (j=0; j<p; j++) {
            A[i][j] = i+j;
        }
    }

    // Set every element B[i][j] to i-j
    for (i=0; i<p; i++) {
        for (j=0; j<q; j++) {
            B[i][j] = i-j;
        }
    }

    // Call the matmult function from matmult file
    matmult(n,p,q,A,B,C);

// Print out all matrices.
    printf("This is matrix A\n");
    print_matrix(n,p,A);
    printf("This is matrix B\n");
    print_matrix(p,q,B);
    printf("This is matrix C\n");
    print_matrix(n,q,C);
}

// Prints a matrix prettly
void print_matrix(int n, int m, double M[n][m])
{
    int i, j;

    for (i=0; i<n; i++) {
        // Print columns
        for(j=0; j<m; j++){
            printf("% 3.0lf ", M[i][j]);
        }
        // New line between each row
        printf("\n");
    }
}