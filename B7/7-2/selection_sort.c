#include <stdio.h>

void sort(int n, double *a)
{
    for (int k = 0; k <= n - 2; k++)
    {
        // Find the index of the minimum value in the range a[k] to a[n-1]
        int minIndex = k;
        for (int i = k; i < n; i++)
        {
            if (a[i] < a[minIndex])
            {
                minIndex = i;
            }
        }

        // Swap the values at a[k] and a[minIndex]
        double temp = a[k];
        a[k] = a[minIndex];
        a[minIndex] = temp;
    }
}
