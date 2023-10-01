#include <stdio.h>

int main()
{
    int k, n, m;

    // k, a, n, mの入力
    fprintf(stderr, "整数 k を入力してください (1≤k≤10): ");
    scanf("%d", &k);

    if (k < 1 || k > 10)
    {
        fprintf(stderr, "kの値が無効です。1から10の範囲内で指定してください。\n");
        return 1;
    }

    int a[10];

    fprintf(stderr, "k 個の整数を入力してください: ");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
    }

    fprintf(stderr, "整数 n を入力してください (k≤n≤16): ");
    scanf("%d", &n);

    if (n < k || n > 16)
    {
        fprintf(stderr, "k以上16以下で指定してください。\n");
        return 1;
    }

    fprintf(stderr, "整数 m を入力してください (1≤m≤16): ");
    scanf("%d", &m);

    if (m < 1 || m > 16)
    {
        fprintf(stderr, "1から16の範囲内で指定してください。\n");
        return 1;
    }

    // m 回の処理
    for (int j = 0; j < m; j++)
    {
        int b[10];
        fprintf(stderr, "n 個の整数を入力してください: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }

        // 条件を満たすかどうかの検証
        int match = 1;
        for (int i = 0; i < n - k + 1; i++)
        {
            for (int x = 0; x < k; x++)
            {
                if (b[i + x] != a[x])
                {
                    match = 0;
                    break;
                }
            }
            if (match == 1)
            {
                break;
            }
        }

        printf("%d\n", match);
    }

    return 0;
}
