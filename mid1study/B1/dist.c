#include <stdio.h>
#include <math.h>

int main (void) {

    int i;
    double x1, x2, y1, y2;
    double dist;

    for ( i = 0; i < 3; i ++) {

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    dist = sqrt(pow(x2 - x1,2)+ pow(y2-y1,2));
    printf("%.4f\n", dist);
    }




    return 0;
}