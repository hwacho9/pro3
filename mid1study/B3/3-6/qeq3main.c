#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "qeq3.h"

int main(void)
{
   double a, b, c;  /* 方程式の係数 */
   int n;           /* 解の個数 */
   double x1, x2;   /* 解 */
   for (;;) {
      scanf("%lf", &a);
      if (fabs(a)<DBL_EPSILON) { break; }   /* aのゼロ判定 */
      scanf("%lf", &b);
      scanf("%lf", &c);
      n = qeq(a,b,c,&x1,&x2);
      if (n==0) {
        printf("\n");
      }
      else if (n==1) {
        printf("%0.5f\n", x1);
      }
      else if (n==2) {
        printf("%0.5f %0.5f\n", x1, x2);
      }
      else {
        assert(0); /* ここに来たらエラー */
      }
   }
   return 0;
}

int qeq(double a, double b, double c, double *x1, double *x2) {
    double d = b * b - ( 4 * a *c );
    int n;
    if ( d == 0 ) {
        *x1 = - b / ( 2 * a);
        n = 1;
    }
    else if ( d > 0 ) {
        *x1 = (-b - sqrt(d)) / 2 *a ;
        *x2 = (-b + sqrt(d)) / 2 *a ;
        n = 2;
    }
    else if ( d < 0 ) {
        n =  0;
    }

    return n;
}