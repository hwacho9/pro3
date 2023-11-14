#include <stdio.h>

void insertion_sort(int n, int a[]);

int main(void)
{
    insertion_sort(10, (int[]){41, 45, 83, 74, 62, 46, 25, 65, 65, 5});

    return 0;
}
void insertion_sort(int n, int a[])
{

    int i, j;
    int tmp;

    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        int t = 0;
        int sum = 0;

        // Move elements of a[0..i-1] that are greater than tmp to one position ahead of their current position
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
            t++;
            sum += t;
        }

        a[j + 1] = tmp;

        // Print the array after each iteration
        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }

        printf("%d ", t);
        printf("\n");
    }
}