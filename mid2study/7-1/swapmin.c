#include <stdio.h>

void swapmin(int n, double *a, int k)
{
    int min = k;
    for (int i = k; i < n; i++)
    {
        if (a[i] < a[min])
        {
            min = i;
        }
    }

    double tmp = a[k];
    a[k] = a[min];
    a[min] = tmp;
}