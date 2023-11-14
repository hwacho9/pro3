#include <stdio.h>

void sort(int n, double *a)
{
    // for (int k = 1; k <= n - 1; k++)
    // {
    //     if (a[k] >= a[k - 1])
    //     {
    //         return;
    //     }
    //     else if (a[k] < a[k - 1])
    //     {
    //         double temp = a[k - 1];
    //         a[k - 1] = a[k];
    //         a[k] = temp;
    //     }
    // }

    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 1; k < n - i; k++)
        {
            if (a[k] < a[k - 1])
            {
                double temp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = temp;
            }
        }
    }
}