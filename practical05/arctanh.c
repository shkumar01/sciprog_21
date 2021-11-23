/*******************************************************
 *                 Week 5 practical
 *               Computing arctanh(x)
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */

// computes arctanh using a maclaurin series with precision delta
float arctanh1(float x, float delta);
// computes arctanh using mathematical identity
float arctanh2(float x);

int main(int argc, char const *argv[])
{
    double delta;
    printf("Please enter a postive real number delta - the precision for the Maclaurin series\n");
    printf("Enter delta: ");

    // Check if input for precision is valid and is not negative
    int err = scanf("%lf", &delta);
    if(err!=1 || delta < 0 ) {
        // Invalid input -> exit the program
        printf("Bad value for delta\n");
        exit(1);
    }

    int i;

    // Told in the question we want to compute the value of arctanh
    // in the interval -0.9 -> 0.9 with spacing 0.01
    float start = -0.9;
    float end = 0.9;
    float spacing = 0.01;

    // Get number total number of points
    // use ceil to round up
    int npoints = (int) ceil((end-start)/spacing);

    // Create arrays to store the values computed by the two functions
    float arctanh1_arr[npoints+1];
    float arctanh2_arr[npoints+1];

    for(i=0; i <= npoints; i++){
        //get the current value to evaluate arctanh for
        float point = start+(i*spacing);
        // compute archtanh using the 2 functions and store the result in their
        // respective arrays
        arctanh1_arr[i] = arctanh1(point, delta);
        arctanh2_arr[i] = arctanh2(point);

        // Output the difference between the two methods
        printf("arctanh1(%.2f)=%f ", point, arctanh1_arr[i]);
        printf("arctanh2(%.2f)=%f ", point, arctanh2_arr[i]);
        printf("Absolute diff is: %.10f\n", fabs(arctanh1_arr[i]-arctanh2_arr[i]));
    }

    return 0;
}

// computes arctanh using a maclaurin series
// Stops when elements in maclurin series are smaller than value delta
float arctanh1(float x, float delta) {
    float arcTanh = 0.0, term;
    int n = 0;
    // do atleast one iteration to at least compute the first term in the series
    // stops when the absolute value of the terms in the series are smaller than given delta
    do
    {
        int factor = (2*n)+1;
        term = pow(x, factor)/(factor);
        arcTanh += term;
        n++;
    } while (fabs(term) >= delta);

    return arcTanh;
}

// Computes the arctanh using the mathematical identity
// archtanh(x) = 1/2 ( ln(1+x) - ln(1-x) )
float arctanh2(float x) {
    return 0.5*(log(1.0 + x) - log(1.0 - x));
}
