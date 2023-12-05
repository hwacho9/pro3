#include <stdio.h>

void sort(int n, double *a)
{
    for (int k = 0; k <= n - 2; k++)
    {
        int minIndex = k;
        for (int i = k; i < n; i++)
        {
            if (a[i] < a[minIndex])
            {
                minIndex = i;
            }
        }

        double tmp = a[k];
        a[k] = a[minIndex];
        a[minIndex] = tmp;
    }
}