#include <stdio.h>

int main(void)
{
   int n; 
   int i; 

   fprintf(stderr, "nを入力して下さい: ");
   scanf("%d", &n);

   for (i=1; i<=n; i++) {
      printf("%d %d\n", i, i*i);
   }


  return 0;
}