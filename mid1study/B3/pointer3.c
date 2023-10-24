#include <stdio.h>

int main(void) {
    int a = 1234;
    int b = 6666;
    double x = 1.23;
    double y = 4.56;

    int *p;
    double *q;

    p = &b;
    q = &x;
    printf("%d\n", *p);
    printf("%p\n", p);

    return 0;
}