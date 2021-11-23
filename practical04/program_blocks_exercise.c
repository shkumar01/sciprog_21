/*******************************************************
 *                 Week 4 practical
 *        Creating additional program blocks
********************************************************/

#include <stdio.h>
#include <math.h>

/* Function prototypes */
// converts given value in degree to radians
float deg2rad(float deg);
// computes the area under tan(x) from x = 0 -> 60 deg (as done in practical 3)
// using the trapezodial rule
float area_under_tan(int npts);

// Global variable Array that holds the values of Tan(x) from x=0->60 deg in increments of 5
float tan_arr[13];

int main(int argc, char const *argv[])
{

    int i, n_pts=13;
    // parts 2,3,4,5 in exercise
    for(i = 0 ; i < n_pts ; i++) {

        // generate angles, ang will go from 0 to 12*5 in increments of 5
        int ang = i*5;
        // convert the angle from degrees to radians using our function
        float ang_in_rad = deg2rad(ang);
        // tan function needs it's input in radians
        tan_arr[i] = tan(ang_in_rad);
        //printf("Tan(%d)=%f\n",ang,tan_arr[i]);
    }

    // call function to calculate area and print it out
    float area = area_under_tan(n_pts);
    printf("Area under curve is = %f\n", area);
    printf("True value for area = log(2) ~= %f\n", log(2));
    printf("Absolute difference is: %f\n", fabs(area - log(2)));

    return 0;
}

// Convert degrees to radians
// Pi rad = 180 deg => 1 deg = pi/180 rad
float deg2rad(float deg) {
    return (M_PI/180.0)*deg;
}

// Area under tan curve
// uses the global array tan_arr to get the values of tan(x) from 0 to 60
float area_under_tan(int npts){

    float area;
    int i;

    // f(x0) + f(xn)
    area = tan_arr[0] + tan_arr[npts-1];

    // Add rest of elements
    for (i = 1; i < npts-1; i++)
    {
        area += 2*tan_arr[i];
    }

    // Multiply by the pre-factor
    area *= deg2rad(60.0-0.0)/(2*(npts-1));

    // Return the computed area
    return area;
};