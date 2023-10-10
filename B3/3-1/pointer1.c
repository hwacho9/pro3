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

  return 0;
}