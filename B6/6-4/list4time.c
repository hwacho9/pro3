#include <stdio.h>
#include "myrand.h"
#include "list.h"
#include "time.h"

int main(void)
{
    clock_t clk_start, clk_end;
    int n;

    list_node_t *head_p = create_node(0);

    clk_start = clock();

    scanf("%d", &n);
    myrand_init();
    for (int i = 0; i < n; i++)
    {
        int a = myrand(); // n個の乱数発生
        // printf("%d\n", a);
        list_insert_uniq(head_p, a);

        // list_print(head_p);
    }
    myrand_init();
    for (int i = 0; i < n; i++) // aと同じ乱数発生
    {
        int b = myrand();
        // printf("%d ", b);
        list_node_t *p = list_find(head_p, b);
        if (p == NULL)
        {
            printf("non");
        }
        else
        {
            // list_print(head_p);
        }
    }

    for (int i = 0; i < n; i++) // aと同じ乱数発生
    {
        int c = myrand();
        // printf("%d ", c);
        list_node_t *p = list_find(head_p, c);
        if (p == NULL)
        {
            // printf("重複される数がないです");
        }
        else
        {
            // list_print(head_p);
        }
    }

    clk_end = clock();
    printf("cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    return 0;
}