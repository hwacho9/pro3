#include <stdio.h>
#include <math.h>

double dist(double, double, double, double);

int main (void) {

    int i;
    double x1, x2, y1, y2;
    double dis;

    for ( i = 0; i < 3; i ++) {

        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        dis = dist(x1, y1, x2, y2);
    printf("%.4f\n", dis);
    }

    return 0;
}

double dist(double x1, double y1, double x2, double y2) {
    double dist = sqrt(pow(x2 - x1,2)+ pow(y2 - y1,2));
    return dist;
}