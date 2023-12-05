#include <iostream>

int main(void)
{
    std::cout << "hello" << std::endl;
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += i;
    }
    std::cout << "sum(1.." << n << ") = " << s << std::endl;
    return 0;
}