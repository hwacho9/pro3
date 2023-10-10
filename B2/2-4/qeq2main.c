#include <stdio.h>
#include "qeq2.h"

int main (void)
{
    double a;
    double b;
    double c;

    for (;;) {
        fprintf(stderr, "a,b,c : ");
        if ( scanf("%lf", &a) == EOF ) {
            break;
        }
        scanf("%lf", &b);
        scanf("%lf", &c);
        qeq(a,b,c);
    }
}
