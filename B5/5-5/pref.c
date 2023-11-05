#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pref.h"

#define NAMELEN 15

pref_t *pref_new(char *name, double area, int population)
{
    pref_t *p = (pref_t *)malloc(sizeof(pref_t));
    if (p != NULL)
    {
        strncpy(p->name, name, NAMELEN);
        p->area = area;
        p->population = population;
    }
    return p;
}

void pref_print(pref_t *p)
{
    if (p != NULL)
    {
        printf("%-10s %9.2f %9d\n", p->name, p->area, p->population);
    }
}
