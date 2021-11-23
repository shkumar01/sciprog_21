/*******************************************************
 *                 Week 7 practical
 *               Calculate the constant e
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */

// computes factorial of number n
int factorial(int n);
// computes the polynomial expression for e upto term `n`
double compute_polynomial(int n, int x);

int main()
{
    int order;
    int size_of_array;
    double *array_of_terms;
    const int value = 1;
    int i;

    // Get input from the user for the order of the polynomial used in the
    // e estimate
    printf("Enter the order of the polynomial: ");
    int err = scanf("%d", &order);

    // Check if scanf was able to read the input entered by the user as an integer
    // or if order is negative
    if (err != 1 || order < 0 ) {
        // Invalid input - exit the program
        printf("Bad value\n");
        exit(-1);
    }

    size_of_array = order+1;

    // dynamically allocate array of size order+1
    array_of_terms = (double *) malloc(sizeof(double)*size_of_array);
    // Check if we've actually been allocated
    if(array_of_terms == NULL){
        printf("Unable to allocate array to store polynomial terms upto order %d", order);
        exit(-2);
    }

    // compute each term in the polynomial upto the order and store in array element
    // corresponding the order of the term
    for(i = 0; i < size_of_array; i++) {
        array_of_terms[i] = compute_polynomial(i,value);
        printf("f[%d] = %0.20lf\n", i, array_of_terms[i]);
    }

    // Actual value
    printf("Actual value e1 = %0.20lf\n", exp(1));

    // Compare estimated to actual value for every polynomial estimate upto order
    for(i=0; i < size_of_array; i++){
        printf("Estimate difference for term %d is %0.20f\n", i, exp(1)-array_of_terms[i]);
    }

    // free up memory
    free(array_of_terms);
    array_of_terms = NULL;

    return 0;
}


// Iteratively computes the factorial of given number n
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int i;
    int fact = 1;
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Computes the polynomial up to order n for value x
double compute_polynomial(int n, int x) {
    double sum = 0.0;
    int i;

    for (i = 0; i <= n; i++) {
        sum += (double) ((pow(x, i) / factorial(i)));
    }
    return sum;
}