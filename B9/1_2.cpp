#include <iostream>

void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

int main(void)
{
    int a = 5;
    int b = 6;
    std::cout << "交換前：";
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "交換後：";
    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}