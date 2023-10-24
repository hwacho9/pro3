#include <stdio.h>
#include <math.h>

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

void qeq (double a, double b, double c) {
    double D = b * b - (4 * a * c);
    double kai1, kai2;

    if ( D == 0 ) {
        kai1 = - b / (2 * a);
        printf("%.5f\n", kai1);
    }
    else if ( D > 0 ){
        kai1 =  ((- b + sqrt(D) ) / (2 * a));
        kai2 =  ((- b - sqrt(D) ) / (2 * a));
        printf("%.5f %.5f\n", kai2, kai1);
    }
    else if ( D < 0 ){
        printf("\n");
    }
}