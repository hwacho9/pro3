#include <stdio.h>
#include <math.h>
#include "dist5.h"

int point_scan(point_t *p) 
{
    if (scanf("%lf", &p->x)==EOF) { return EOF; }
    if (scanf("%lf", &p->y)==EOF) { return EOF; }

    return 1;
}

double dist(point_t *p1, point_t *p2)
{
    return sqrt(pow((p1->x - p2->x),2) + pow((p1->y - p2->y),2));
}