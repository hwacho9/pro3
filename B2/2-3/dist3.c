#include <stdio.h>
#include <math.h>
#include "dist3.h"

double dist(double x1, double y1, double x2, double y2)
{
    double a = sqrt(pow((x2 - x1),2) + pow((y2 -y1),2));
    return a;
}