/*******************************************************
 *                 Week 5 practical
 *               The Fibonacci series
********************************************************/

#include <stdio.h>
#include <stdlib.h>

// Function that computes the next iteration of fibonacci series
// given f_n-1 and f_n-2 as input

void fib(int *fn_1, int *fn_2) {
    // Temporary variable to store the value pointed by Fn-1
    int tmp = *fn_1;
    // Compute Fn and set the value pointed by Fn-1 as that
    *fn_1 = *fn_1 + *fn_2; // * dereferences variable so changes are done to the
                           // value in the memory location pointed by the variable
    // The old Fn-2 becomes Fn-1
    *fn_2 = tmp;
}

int main(int argc, char const *argv[])
{
    int n, i;

    // Get user input
    printf("Please enter the value of n upto which Fib(n) should be computed\n");
    printf("Enter n:\t");
    int err = scanf("%d", &n);

    // From practical 2
    // Check if scanf was able to read the input entered by the user as an integer
    if(err != 1) {
        // Invalid input - exit the program
        printf("Bad value\n");
        exit(-1);
    }

    // Initial values of the Fibonaci sequence F0 = 0, F1 = 1
    int fn_2=0, fn_1=1;

    for(i=0; i<n; i++) {
        printf("F%d=%d, F%d=%d\n", i,fn_2, i+1,fn_1);
        fib(&fn_1, &fn_2);
    }

    return 0;
}
