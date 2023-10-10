#include <stdio.h>
#include "dist3.h"

#define REPEAT 3

int main(void) {
    double x1;
    double x2;
    double y1;
    double y2;

    double dis;

    for (int r = 0; r < REPEAT; r++) {
        fprintf(stderr, "4つの実数 (x1, y1), (x2, y2)を入力して下さい");
        scanf("%lf", &x1);
        scanf("%lf", &y1);
        scanf("%lf", &x2);
        scanf("%lf", &y2);

        dis = dist(x1, y1, x2, y2);
        printf("%0.4f\n", dis);
    }
}