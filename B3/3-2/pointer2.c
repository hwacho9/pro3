#include <stdio.h>

int main(void)
{
  int a = 1234; 
  int b = 6666; 
  double x = 1.23; 
  double y = 4.56;

  printf("a の番地は %p\n", &a);
  printf("b の番地は %p\n", &b);
  printf("x の番地は %p\n", &x);
  printf("y の番地は %p\n", &y);

  printf("\n");
  printf("a の値 = %d\n", *((int*)0x16db7f018));  /* 0x16f1cefb8 (a) の内容を出力 */
  printf("b の値 = %d\n", *((int*)0x16db7f014));  /* 0x16f1cefb4番地 (b) の内容を出力 */
  printf("x の値 = %f\n", *((double*)0x16b4ef008));  /* 0x16f1cefb4番地 (c) の内容を出力 */
  printf("y の値 = %f\n", *((double*)0x16b4ef000));  /* 0x16f1cefb4番地 (c) の内容を出力 */

  *((int*)0x16db7f018) = 1111;  /* 0x16f1cefb8 (a) に1111を書き込む */
  *((int*)0x16db7f014) = 2010;  /* 0x16f1cefb4番地 (b) に2010を書き込む */
  *((double*)0x16b4ef008) = 3.33;  /* 0x16dc番地 (c) に5628を書き込む */
  *((double*)0x16b4ef000) = 4.44;  /* 0x16dc番地 (c) に5628を書き込む */

  printf("\n");
  printf("a の値 = %d\n", a);
  printf("b の値 = %d\n", b);
  printf("x の値 = %f\n", x);
  printf("y の値 = %f\n", y);

  return 0;
}