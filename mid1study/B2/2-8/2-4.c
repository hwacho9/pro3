#include <stdio.h>
#include <stdlib.h>   /* rand() を使うときには stdlib.h が必要 */

int main( void )
{
   int i, seed, r;

   printf("乱数の最大値 RAND_MAX = %d\n", RAND_MAX);

   printf("乱数の種となる整数を入力して下さい > ");
   scanf("%d",&seed);
   srand(seed); /* 種の設定 */

   /* 一様乱数を 10 回発生させて表示 */
   for (i=0; i<10; i++) {
      r = rand();
      printf("%d\n", r);
   }

   return 0;
}