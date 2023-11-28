#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn);

int main(void)
{
    int *a = NULL;
    int i, n;

    a = new_array_scan(&n);

    int max = a[0];
    int min = a[0];
    for (i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        if (min > a[i])
        {
            min = a[i];
        }
    }

    int count_size = max - min + 1;
    int *count = (int *)malloc(sizeof(int) * count_size);

    if (count == NULL)
    {
        exit(1);
    }

    for (i = 0; i < count_size; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }

    for (i = 0; i < count_size; i++)
    {
        if (count[i] > 0)
        {
            printf("%d: %d\n", i + min, count[i]);
        }
    }

    free(count);
    free(a);
    count = NULL;
    a = NULL;

    return 0;
}