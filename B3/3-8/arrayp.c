#include <stdio.h>


int main(void) {
    int x[ ] = {0,10,20,30,40};
/* x[0]=0, x[1]=10, x[2]=20, x[3]=30, x[4]=40 と初期化される */

    int k = sizeof(x)/sizeof(x[0]);

    for ( int i = 0; i < k; i++)
    {
        printf("%d ", x[i]);
        printf("%p\n", &x[i]);
    }

    return 0;
}