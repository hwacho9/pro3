#include <stdio.h>
#include <string.h>  /* strncpy を使うため */

#define NM_LEN 31
#define NM_FMT "%31s"

typedef struct {
  char name[NM_LEN+1];  /* 品物の名前 */
  int price;            /* 価格 */
  double weight;        /* 重量 */
} item_t;


void item_print(item_t x);
int item_sum_price(item_t a, item_t b, item_t c);
double item_sum_weight(item_t a, item_t b, item_t c);


int main(void)
{
   item_t a, b, c;  /* 3つの品物 */
   int sum_price;
   double sum_weight;

   /* 値の設定 */
   a.name[NM_LEN] = '\0';
   strncpy(a.name, "apple", NM_LEN);
   a.price = 120;
   a.weight = 205.82;

   b.name[NM_LEN] = '\0';
   strncpy(b.name, "banana", NM_LEN);
   b.price = 220;
   b.weight = 423.64;

   c.name[NM_LEN] = '\0';
   strncpy(c.name, "cherry", NM_LEN);
   c.price = 150;
   c.weight = 270.53;

   /* データの出力 */
   item_print(a);
   item_print(b);
   item_print(c);

   /* 和の計算と出力 */
   sum_price = item_sum_price(a,b,c);
   printf("%d\n", sum_price);
   sum_weight = item_sum_weight(a,b,c);
   printf("%0.2f\n", sum_weight);

   return 0;
}


void item_print(item_t x)
{
   printf("%s", x.name);
   printf(",%d", x.price);
   printf(",%0.2f", x.weight);
   printf("\n");
}


int item_sum_price(item_t a, item_t b, item_t c)
{
   return a.price + b.price + c.price;
}


double item_sum_weight(item_t a, item_t b, item_t c)
{
   return a.weight + b.weight + c.weight;
}