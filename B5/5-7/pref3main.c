#include <stdio.h>
#include <stdlib.h>
#include "pref.h"

#define MAX_PREFS 47

int main(void)
{
    pref_t *prefs[MAX_PREFS];
    int count = 0;

    for (int i = 0; i < MAX_PREFS; i++)
    {
        prefs[i] = pref_new_scan();
        if (prefs[i] == NULL)
            break;
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        pref_print(prefs[i]);
        free(prefs[i]);
    }

    return 0;
}