#include <iostream>

int main(void)
{
    int *a = 0;
    a = 0;       // ポインタの宣言
    a = new int; // int1個分の領域を割り当て,そこへのポインタを
    *a = 100;
    std::cout << *a << std::endl;
    delete a; // 領域の解放

    return 0;
}
