#include <stdio.h>

int main(void)
{
  int a = 1234; 
  int b = 6666; 
  int c = 9876; 

  printf("a の番地は %p\n", &a);
  printf("b の番地は %p\n", &b);
  printf("c の番地は %p\n", &c);

  printf("\n");
  printf("a の値 = %d\n", *((int*)0x16d60efb8));  /* 0x16f1cefb8 (a) の内容を出力 */
  printf("b の値 = %d\n", *((int*)0x16d60efb4));  /* 0x16f1cefb4番地 (b) の内容を出力 */
  printf("c の値 = %d\n", *((int*)0x16d60efb0));  /* 0x16f1cefb4番地 (c) の内容を出力 */

  *((int*)0x16d60efb8) = 1111;  /* 0x16f1cefb8 (a) に1111を書き込む */
  *((int*)0x16d60efb4) = 2010;  /* 0x16f1cefb4番地 (b) に2010を書き込む */
  *((int*)0x16d60efb0) = 5628;  /* 0x16dc番地 (c) に5628を書き込む */

  printf("\n");
  printf("a の値 = %d\n", a);
  printf("b の値 = %d\n", b);
  printf("c の値 = %d\n", c);

  return 0;
}