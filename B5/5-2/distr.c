#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn);

int main(void)
{
    int n;
    int *arr = new_array_scan(&n);

    if (arr == NULL)
    {
        printf("Input error\n");
        return 1;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
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
        count[arr[i] - min]++;
    }

    for (int i = 0; i < count_size; i++)
    {
        if (count[i] > 0)
        {
            printf("%d: %d\n", i + min, count[i]);
        }
    }

    free(arr);
    free(count);

    return 0;
}
