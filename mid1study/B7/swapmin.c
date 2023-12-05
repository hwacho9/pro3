#include <stdio.h>

void swapmin(int n, double *a, int k)
{
    int minIndek = k;
    for (int i = k; i < n; i++)
    {
        if (a[i] < a[minIndek])
        {
            minIndek = i;
        }
    }

    double tmp = a[k];
    a[k] = a[minIndek];
    a[minIndek] = tmp;
}
