#include <stdio.h>
#include "matrix.h"

int main(void)
{
   int n;
   double A[N][N], x[N], y[N];

   fprintf(stderr, "n = ");
   scanf("%d", &n);
   fprintf(stderr, "A\n");
   matrix_scan(n, A);
   fprintf(stderr, "x\n");
   vector_scan(n, x);

   matrix_vector_prod(n, A, x, y);

   printf("A\n");
   matrix_print(n, A);
   printf("x\n");
   vector_print(n, x);
   printf("y\n");
   vector_print(n, y);

   return 0;
}