#include <stdio.h>

void bubble_sort(int n, int a[]);
void swap(int *x, int *y);

int main(void)
{
    bubble_sort(10, (int[]){41, 45, 83, 74, 62, 46, 25, 65, 65, 5});
    // bubble_sort(5, (int[]){43, 80, 53, 8, 45});

    return 0;
}

void bubble_sort(int n, int a[])
{
    int i, j;
    int tmp;
    int t = 0;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j <= n - 2; j++)
        {
            if (a[j] > a[j + 1])
            {
                // Swap elements if they are in the wrong order
                swap(&a[j], &a[j + 1]);
                t++;
            }
        }

        // Print the array after each iteration
        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("%d ", t);
        printf("\n");
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
