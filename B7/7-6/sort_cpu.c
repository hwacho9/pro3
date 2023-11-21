#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MIN_N 2
#define MAX_N 8
#define N_TEST 8

void sort(int n, double *a);

void array_set_rand(int n, double *a)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}

void array_set_sorted(int n, double *a)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

void array_set_reverse(int n, double *a)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i - 1;
    }
}

void array_copy(int n, double *a, double *r)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = r[i];
    }
}

void sort_check(int n, double *a)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            ; // OK
        }
        else
        {
            fprintf(stderr, "sort error (a[%d]=%0.10f, a[%d]=%0.10f)\n", i, a[i], i + 1, a[i + 1]);
            exit(1);
        }
    }
}

void sort_cpu(double *r)
{
    int n;
    int i;
    double *a;
    int t0, t1;

    for (i = 0; i < N_TEST; i++)
    {
        printf("%18.5f\n", r[i]);
    }

    for (n = MIN_N; n <= MAX_N; n *= 2)
    {
        printf("n = %d\n", n);

        a = (double *)malloc(sizeof(double) * n);
        if (a == NULL)
        {
            fprintf(stderr, "malloc に失敗 (n = %d)\n", n);
            exit(1);
        }

        array_copy(n, a, r);

        clock_t clk_start, clk_end;
        clk_start = clock();

        sort(n, a);

        clk_end = clock();
        printf("cpu = %11.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);

        sort_check(n, a);

        free(a);
        a = NULL;
    }
}

int main(void)
{
    double *r;
    int i;

    r = (double *)malloc(sizeof(double) * MAX_N);
    if (r == NULL)
    {
        fprintf(stderr, "malloc に失敗 (MAX_N = %d)\n", MAX_N);
        exit(1);
    }

    printf("乱数\n");
    array_set_rand(MAX_N, r);
    sort_cpu(r);

    printf("正順\n");
    array_set_sorted(MAX_N, r);
    sort_cpu(r);

    printf("逆順\n");
    array_set_reverse(MAX_N, r);
    sort_cpu(r);

    free(r);
    r = NULL;

    return 0;
}
