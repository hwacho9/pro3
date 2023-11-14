#include <stdio.h>
#include <stdlib.h>

void insert(int n, double *a, int k)
{
    for (int i = k; i >= 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            double temp = a[i - 1];
            a[i - 1] = a[i];
            a[i] = temp;
        }
        else if (a[i] >= a[i - 1])
        {
            return;
        }
    }
}