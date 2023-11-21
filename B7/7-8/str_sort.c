// str_sort.h
#include <string.h>
#include "str_sort.h"

#define STRLEN 63
#define STRFMT "%63s"

void str_sort(int n, record_t *a)
{
    for (int k = 0; k <= n - 2; k++)
    {
        // Find the index of the minimum value in the range a[k] to a[n-1]
        int minIndex = k;
        for (int i = k; i < n; i++)
        {
            // Compare first by age, and then by height if ages are equal
            if (a[i].age < a[minIndex].age || (a[i].age == a[minIndex].age && a[i].height < a[minIndex].height))
            {
                minIndex = i;
            }
        }

        // Swap the values at a[k] and a[minIndex]
        record_t temp = a[k];
        a[k] = a[minIndex];
        a[minIndex] = temp;
    }
}
