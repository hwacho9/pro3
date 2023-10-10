#include <stdio.h>
#include <math.h>
#include "qeq2.h"

void qeq(double a, double b, double c)
{
    double D = b * b - (4 * a * c);

    if(D==0) {
        printf("%.5lf\n", -b / (2 * a));
    }
    else if ( D < 0 )
    { 
        printf("\n");
    }
    else if ( D > 0 ) {
        double t1 = (-b - (sqrt(b*b- 4*a*c)))/(2*a);
        double t2 = (-b + (sqrt(b*b- 4*a*c)))/(2*a);
        if ( t1 > t2 )
        {
            printf("%.5lf", t2);
            printf(" ");
            printf("%.5lf\n", t1);
        }
        else if ( t1 < t2 )
        {
            printf("%.5lf", t1);
            printf(" ");
            printf("%.5lf\n", t2);
        }
    }
}