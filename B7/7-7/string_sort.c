// string_sort.h
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "string_sort.h"
#define MAX_N 64

void string_sort(int n, char (*a)[STRLEN + 1])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 1; k < n - i; k++)
        {
            if (strcmp(a[k], a[k - 1]) < 0)
            {
                char temp[STRLEN + 1];
                strcpy(temp, a[k - 1]);
                strcpy(a[k - 1], a[k]);
                strcpy(a[k], temp);
            }
        }
    }
}
