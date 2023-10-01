#include <stdio.h>
#include <math.h>  /* 平方根関数 sqrt を用いる場合に必要 */

#define REPEAT 3    /* 繰り返し回数 */

int main(void)
{
   int r; 
   double a; 
   double b; 
   double ave_a;  /* 相加平均 */
   double ave_m;  /* 相乗平均 */

   for (r=0; r<REPEAT; r++) {
      fprintf(stderr, "2つの実数 a, b を入力して下さい: ");   /* プロンプトは標準エラーに */
      scanf("%lf", &a);
      scanf("%lf", &b);
      ave_a = (a+b)/2;
      ave_m = sqrt(a*b);
      printf("%0.3f %0.3f\n", ave_a, ave_m);
   }

   return 0;
}