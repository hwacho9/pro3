#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(*pn);

int main(void)
{
    int n;
    int *a = new_array_scan(&n);

    int min = a[0];
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        of(a[i] > max)
        {
            max = a[i];
        }
    }

    int count_size = max - min + 1;
    int *count = (int *)malloc(sizeof(int) * count_size);

    if (count == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < count_size; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }

    for (int i = 0; i < count_size; i++)
    {
        if (count[i] > 0)
        {
            printf("%d: %d\n", i + min, count[i]);
        }
    }

    free(a);
    free(count);

    return 0;
}