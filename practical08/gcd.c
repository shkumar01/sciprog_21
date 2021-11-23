/*******************************************************
 *                 Week 8 practical
 * Euclidian gcd algorithm iteratively and recursively
********************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main(){

    int a, b, error;

    // Get user input for two numbers to compute the GCD of
    printf("Please input two positive integers:\n");
    error = scanf("%d %d", &a, &b);

    // Validate input
    if (error != 2) {
        printf("Invalid input, please try again\n");
        return 1;
    }
    if (a<=0||b<=0) {
        printf("These numbers are not positive!\n");
        return 1;
    }

    // Print the GCD using both implementations
    printf("Iterative GCD(%d,%d) = %d\n", a, b, iterativeGCD(a, b));
    printf("Recursive GCD(%d,%d) = %d\n", a, b, recursiveGCD(a, b));

    return 0;
}

// GCD implemented iteratively following
// pseduo code given in the practical 8 pdf
int iterativeGCD(int a, int b){
    while(b != 0) {
        int temp = b;
        b = a%b; // Get reminder dividing A/B, if this is 0 then a is the GCD
        a = temp;
    }
    return a;
}

// GCD implemented recursively following
// pseduo code given in the practical 8 pdf
int recursiveGCD(int a, int b){
    if (b == 0){
        return a;
    }
    else {
        recursiveGCD(b, a%b); // keep calling same function until b divides without remainder into a
    }
}