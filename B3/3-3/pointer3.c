#include <stdio.h>

int main(void)
{
  int a = 1234; 
  int b = 6666; 
  double x = 1.23;
  double y = 4.56;

  int *p; 
  double *q;

  printf("aの番地 = %p\n", &a);
  printf("bの番地 = %p\n", &b);
  printf("xの番地 = %p\n", &x);
  printf("yの番地 = %p\n", &y);

  /* ポインタ変数 p を用いた a の読み書き */
  p = &b;   /* b の番地を p に格納 */
  q = &x;
  printf("b内容 = %d\n", *p);   /* *p は p 番地の内容 (つまり a) */
  printf("x内容 = %.3f\n", *q);   /* *p は p 番地の内容 (つまり a) */
  *p = *p + 4;   /* p 番地の内容 (つまり a) を 1 増やす */
  *q = *q * 2;   /* p 番地の内容 (つまり a) を 1 増やす */
  printf("b内容 = %d\n", *p);
  printf("x内容 = %.3f\n", *q);

  /* 入力した番地の内容を表示 */
  for (;;) {
    printf("番地を入力 : ");
    scanf("%p",&q);
    if (p==0) { break; }
    printf("%p 番地の内容は %f\n", q, *q);
  }

  return 0;
}