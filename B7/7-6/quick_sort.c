// quick_sort.c

void sort(int n, double *a)
{
    int l, r;
    double p;

    if (n <= 1)
    {
        return;
    }

    l = 0;
    r = n - 1;
    p = a[0];

    while (l <= r)
    {
        while (a[l] < p)
        {
            l++;
        }
        while (a[r] > p)
        {
            r--;
        }

        if (l <= r)
        {
            double temp = a[l];
            a[l] = a[r];
            a[r] = temp;

            l++;
            r--;
        }
    }

    if (r > 0)
    {
        sort(r + 1, a);
    }
    if (l < n - 1)
    {
        sort(n - l, &a[l]);
    }
}
