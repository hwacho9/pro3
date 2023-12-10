#include <iostream>

void inc(int x)
{                                         // 整数値xを受取って,
    x++;                                  // それを1増やして,
    std::cout << "x= " << x << std::endl; // 表示する
}

int main(void)
{
    int a = 5;
    inc(a);                               // aを引数にしてincを呼び出すと,
    std::cout << "a= " << a << std::endl; // aの値は変化するか?
    return 0;
}