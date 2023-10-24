#include <stdio.h>
#include <stdlib.h>   /* rand() を使うときには stdlib.h が必要 */


int rand_10_13()
{
   int r = rand() % 4 + 10;
   return r;
}


int main( void )
{
   int i, r;

   for (i=0; i<30; i++) {
      r = rand_10_13();
      printf("%3d", r);
   }
   printf("\n");

   return 0;
}