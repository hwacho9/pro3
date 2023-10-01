#include <stdio.h>
#include <math.h>

int main(void)
{
   double a; 
   double b; 
   double ave_a;  /* 相加平均 */
   double ave_m;  /* 相乗平均 */

   for (;;) {  /* 無限ループ */
      fprintf(stderr, "2つの実数 a, b を入力して下さい: ");
      if (scanf("%lf", &a)==EOF) { break; }  /* 入力がなければループ脱出 */
      if (scanf("%lf", &b)==EOF) { break; }  /* 入力がなければループ脱出 */
      ave_a = (a+b)/2;
      ave_m = sqrt(a*b);
      printf("%0.3f %0.3f\n", ave_a, ave_m);
   }

   return 0;
}