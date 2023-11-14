#include <stdio.h>

int main(void)
{
    // int i, j;
    // int tmp;
    // int a[];
    // int n = 10;

    // for (i = 1; i < n; i++)
    // {
    //     tmp = a[i];
    //     for (j = 1; j >= 0; &&a[j] > tmp; j--)
    //     {
    //         a[j + i] = a[j];
    //         a[j + 1] = tmp;
    //     }
    // }

    // printf("%d", a[]);
    // return 0;

    int j, a = 0;
    for (j = 0; j <= 10; j++)
    {
        a = +j;
    }
    printf("1부터 100까지의 합 = %d\n", a);

    int i, sum = 0;
    for (i = 1000; i <= 2000; i++)
    {
        sum += i;
    }
    printf("1부터 100까지의 합 = %d\n", sum);
}