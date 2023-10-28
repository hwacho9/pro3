#include "dice3sub.h"
#include <stdlib.h>

void dice_throw(int d[], int n) {
    for (int i = 0; i < n; i++) {
        d[i] = (rand() % 6) + 1;
    }
}


void dice3_distr(int n, int d1[], int d2[], int d3[], int c[]) {
    for (int i = D3_MIN; i <= D3_MAX; i++) {
        c[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int s = d1[i] + d2[i] + d3[i];
        c[s]++;
    }
}
