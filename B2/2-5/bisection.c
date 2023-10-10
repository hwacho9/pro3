#include <stdio.h>
#include <math.h>
#include "bisection.h"


// ax^2 + bx + c
double bisection(double x1, double x2, double a, double b, double c, double eps) 
{
    // double xmid =  (x1 + x2)/2;
    double f1 = (a * x1 * x1 + b * x1 + c);
    // double fmid = (a * xmid * xmid + b * xmid + c);
    double f2 = (a * x2 * x2 + b * x2 + c);

    fprintf(stderr, "   i       x1        x2      xmid          f1           f2           fmid\n");

    while (fabs(x1 - x2) > eps) {
        int i = 0;
        double xmid = (x1 + x2) / 2;
        double fmid = a * xmid * xmid + b * xmid + c;
        
        fprintf(stderr, "%3d  %0.8f  %0.8f  %0.8f  %0.8f  %0.8f  %0.8f\n", i, x1, x2, xmid, f1, f2, fmid);

        if (fabs(f1) < eps) {
            // f(xmid) が十分に0に近い場合、xmidを解として返す
            return x1;
        } 
        if ((fabs(f1) > eps) && (fabs(f2) < eps)) {
            return x2;
        }

        if (f1 * fmid < 0) {
            // f(x1) と f(xmid) の符号が異なる場合、解は [x1, xmid] の範囲にある
            x2 = xmid;
            f2 = fmid;
        } else {
            // f(xmid) と f(x2) の符号が異なる場合、解は [xmid, x2] の範囲にある
            x1 = xmid;
            f1 = fmid;
        }

        i++;
    }

    return x1;

    // if ( f1 * fmid < 0  )
    // {
    //     printf("f1 fmid different\n");
    //     x1 = x1;

    // }
    // else if ( fmid * f2  < 0 )
    // {
    //     printf("f2 fmid different");
    //     x2 = x2;
    // }
    // if ( fabs( f1 ) < eps ) 
    // {
    //     answer = f1;
    // }

    
    // fprintf(stderr, "x1 x1 xmid f1 f2 fmid\n");
    // fprintf(stderr, " %.8lf, %.8lf, %.8lf, %.8lf, %.8lf, %.8lf\n",  x1, x2, xmid, f1, f2, fmid);

    // return answer;
}