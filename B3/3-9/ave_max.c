#include <stdio.h>
#include "ave_max.h"

int array_scan(int a[ ])
{
    int i;
    for ( i = 0; i < MAX; i++)
    {
        fprintf(stderr, "a[%d] = ", i);
        if (scanf( "%d", &a[i])==EOF) { break; }
    }

    return i;
}

void array_ave_max(int n, int a[ ], double *ave, int *max)
{
    
    int sum = a[0];
    *max = a[0];

    for ( int i = 1; i < n; i ++) {
        sum += a[i];
        if ( a[i] > *max ) {
            *max = a[i];
        }
    }

    *ave = (double)sum / n;
}