/*******************************************************
 *                 Week 3 practical
 *     Area under curve using the trapezodial rule
********************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // lower and upper limit of integration
    float a = 0.0, b = M_PI/3;
    // number of points to evaluate f(x) in between 0->pi/3
    int npoints = 12;
    // Loop variable
    int i;
    // stepsize to have 11 equidistant points between 0->pi/3
    float stepsize = (b - a) / npoints;
    // trapezodial rule prefactor expression
    float prefactor = (b - a) / (2 * npoints);

    // f(x0) + f(xn)
    float area = tan(a) + tan(b);

    // Start at i=1 as we don't want to include inital value 'a' and end at less than npoints as
    // we don't want to include 'b'
    for(i = 1; i < npoints; i++)
    {
        float xi = a + (i*stepsize);
        //printf("%f\t", xi);
        // Add 2f(xi) for every point xi between 0->pi/3
        area += 2*tan(xi);
    }

    area = prefactor*area;

    printf("Area under curve is = %f\n", area);
    printf("True value for area = log(2) ~= %f\n", log(2));
    printf("Difference is: %f\n", area-log(2));

    return 0;
}
