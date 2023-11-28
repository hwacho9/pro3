#include <stdio.h>
#include <stdlib.h>

int *create_iarray_n_d(int n, int d)
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int) * n);
    if (p == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = d;
    }
    return p;
}
double *create_darray_n_d(int n, double d)
{
    double *p = NULL;
    p = (double *)malloc(sizeof(double) * n);

    if (p == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = d;
    }

    return p;
}