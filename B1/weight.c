#include <stdio.h>

int main()
{
    int n;
    double weight[10];
    double total = 0.0;
    int itemNumber;

    fprintf(stderr, "品物の数を入力してください: ");
    scanf("%d", &n);

    if (n > 10)
    {
        fprintf(stderr, "品物の上限は10です。\n");
        return 1;
    }

    fprintf(stderr, "各品物の重さを入力してください (小数点以下1桁まで): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &weight[i]);
    }

    fprintf(stderr, "品物の番号を入力してください ");

    for (;;)
    {
        if (scanf("%d", &itemNumber) == EOF)
        {
            break;
        }

        total += weight[itemNumber];
    }

    printf("%.1lf\n", total);

    return 0;
}