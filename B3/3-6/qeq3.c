#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "qeq3.h"

int qeq(double a, double b, double c, double *x1, double *x2) 
{
    int n;
    double D = b * b - (4 * a * c);

    if(D==0) {
        *x1 = (-b / (2 * a));
        n = 1;
    }
    else if ( D < 0 )
    { 
        n = 0;
    }
    else if ( D > 0 ) {
        n = 2;
        double t1 = (-b - (sqrt(b*b- 4*a*c)))/(2*a);
        double t2 = (-b + (sqrt(b*b- 4*a*c)))/(2*a);
        if ( t1 > t2 )
        {
            *x1 = t2;
            *x2 = t1;
        }
        else if ( t1 < t2 )
        {
            *x1 = t1;
            *x2 = t2;
        }
    }

    return n;
}