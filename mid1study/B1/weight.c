#include <stdio.h>
#define MAX 100

int main (void) {
    int n, i, c;
    double total;
    double weight[MAX];

    scanf("%d", &n);

    for ( i=0; i<n; i++) {
        weight[i] = 0;
    }

    for( i = 0; i < n; i++ ) {
        scanf("%lf", &weight[i]);
    }

    for (;;) {
        if (scanf("%d", &c)==EOF) {break;}
        total += weight[c];
    }

    printf("%.1f\n", total);
    return 0;

}