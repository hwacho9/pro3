#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn)
{
    int *a = NULL;

    scanf("%d", pn);

    a = (int *)malloc(sizeof(int) * *pn);

    if (a == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < *pn; i++)
    {
        scanf("%d", &a[i]);
    }

    return a;
}