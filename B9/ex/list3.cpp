#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int *a = new int[n]; // 整数n個分の領域を割り当て, その先頭へのポインタを返す.

    for (int i = 0; i < n; i++)
        a[i] = i;
    delete[] a; // deleteの後の[]を忘れないこと(忘れると悲惨!)
    return 0;
}