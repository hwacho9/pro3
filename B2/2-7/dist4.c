#include <stdio.h>
#include <math.h>
#include "dist4.h"

double dist(point_t p1, point_t p2)
{
    double a = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
    return a;
}