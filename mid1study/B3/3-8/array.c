#include <stdio.h>


int main(void) {
    int x[ ] = {0,10,20,30,40};
/* x[0]=0, x[1]=10, x[2]=20, x[3]=30, x[4]=40 と初期化される */

    int k = sizeof(x)/sizeof(x[0]);

    for ( int i = 0; i < k; i++)
    {
        printf("x[%d] : %d, ", i, x[i]);
        printf("x[%d] の値 (アドレス) : %p\n", i, &x[i]);
    }

    printf("x の値 (アドレス) : %p\n", &x);

    for ( int i = 0; i < k; i++)
    {
        printf("x+%d に格納されているデータの値 : %d, ", i, *(x + i));
        printf("x+%d (アドレス) : %p\n", i, &x + i);
    }

    int *p;
    p = &x[2];
    printf("%p\n", p+2);
    printf("%d\n", p[2]);

    return 0;
}