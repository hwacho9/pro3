#include <stdio.h>

int main(void)
{

    int cpm = 600;
    int n = 66000;
    int result;

    result = cpm * n / 1000;

    printf("%d per day\n", result);
    printf("%d per months\n", result * 30);

    return 0;
}