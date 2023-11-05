#include <stdio.h>
#include <stdlib.h>

int *new_array_scan(int *pn)
{
    int *a = NULL;
    // まず整数 n を読み込む
    if (scanf("%d", pn) != 1)
    {
        // n の読み込みに失敗した場合
        return NULL;
    }

    // サイズ n の int 型配列を割り当てる
    a = (int *)malloc(sizeof(int) * *pn);
    if (a == NULL)
    {
        // メモリ割り当てに失敗した場合
        exit(1);
    }

    // n 個の整数を標準入力から配列に読み込む
    for (int i = 0; i < *pn; i++)
    {
        scanf("%d", &a[i]);
    }

    return a;
}