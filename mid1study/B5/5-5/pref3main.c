#include <stdio.h>
#include <stdlib.h>
#include "pref.h"

#define MAX 47

int main(void)
{
    pref_t *p[MAX];
    int count = 0;

    for (int i = 0; i < MAX; i++)
    {
        p[i] = pref_new_scan();
        if (p[i] == NULL)
        {
            break;
        }
        count++;
    }

    for (int i = count; i >= 0; i--)
    {

        pref_print(p[i]);
    }
    return 0;
}