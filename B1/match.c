#include <stdio.h>

int main()
{
    int k, n, m;

    fprintf(stderr, "k: ");
    fprintf(stdout, "\n");
    scanf("%d", &k);

    if (k < 1 || k > 10)
    {
        fprintf(stderr, "kの値が無効です。1から10の範囲内で指定してください。\n");
        fprintf(stdout, "\n");
        return 1;
    }

    int a[10];

    fprintf(stderr, "%d個の整数: ", k);
    fprintf(stdout, "\n");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
    }

    fprintf(stderr, "n: ");
    fprintf(stdout, "\n");
    scanf("%d", &n);

    if (n < k || n > 16)
    {
        fprintf(stderr, "k以上16以下で指定してください。\n");
        fprintf(stdout, "\n");
        return 1;
    }

    fprintf(stderr, "m : ");
    fprintf(stdout, "\n");
    scanf("%d", &m);

    if (m < 1 || m > 16)
    {
        fprintf(stderr, "1から16の範囲内で指定してください。\n");
        return 1;
    }

    // m 回の処理
    for (int j = 0; j < m; j++)
    {
        int b[16];
        fprintf(stderr, "%d個の整数を入力してください: ", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }

        int match = 0;
        for (int i = 0; i <= n - k; i++) // 途中
        {
            int isPattern = 1;
            for (int x = 0; x < k; x++)
            {
                if (b[i + x] != a[x])
                {
                    isPattern = 0;
                    break;
                }
            }
            if (isPattern == 1)
            {
                match = 1;
                break;
            }
        }

        printf("%d\n", match);
    }

    return 0;
}
