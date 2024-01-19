#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myrand.h"
#include "list.h"

int main(void)
{
    clock_t clk_start, clk_end;
    int n;

    list_node_t *head_p = create_node(0);

    // 標準入力から正整数 n を入力
    printf(" n: ");
    scanf("%d", &n);

    // 処理(1): 乱数を n 個発生させ、list_insert_uniq で順次リストに挿入する
    myrand_init();
    clk_start = clock();
    for (int i = 0; i < n; i++)
    {
        int a = myrand();
        list_insert_uniq(head_p, a);
    }
    clk_end = clock();
    printf("(1) cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    // 処理(2): (1)と同じ乱数を n 個発生させ、list_find でそのデータをリスト中に検索する
    myrand_init();
    clk_start = clock();
    for (int i = 0; i < n; i++)
    {
        int b = myrand();
        list_node_t *p = list_find(head_p, b);
        // ここで p を使用しないため、コンパイラの最適化で消される可能性があります
    }
    clk_end = clock();
    printf("(2) cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    // 処理(3): (1)と異なる乱数を n 個発生させ、list_find でそのデータをリスト中に検索する
    clk_start = clock();
    for (int i = 0; i < n; i++)
    {
        int c = myrand();
        list_node_t *p = list_find(head_p, c);
        // ここで p を使用しないため、コンパイラの最適化で消される可能性があります
    }
    clk_end = clock();
    printf("(3) cpu = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

    // メモリ解放

    return 0;
}
