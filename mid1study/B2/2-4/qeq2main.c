#include <stdio.h>
#include "qeq2.h"

void qeq(double , double , double );

int main ( void ) {
    double a, b, c;


    for ( ;; ) {
        if(scanf("%lf", &a) == EOF ) { break;}   
        scanf("%lf %lf", &b, &c);   
        
        qeq(a,b,c);
    }

    return 0;
}
