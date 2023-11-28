#include <stdio.h>

void insert(int n, double *a, int k)
{
    for (int i = k; i >= 0; i--)
    {
        if (a[i] >= a[i - 1])
        {
            break;
        }
        else if (a[i] < a[i - 1])
        {
            double tmp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = tmp;
        }
    }
}