#include <iostream>

int main(void)
{
    std::cout << "hello, plese enter the money you want to exchange" << std::endl;

    double n;

    std::cout << "money(円) => ";
    std::cin >> n;

    double s = n * 0.0068;
    std::cout << s << "($)" << std::endl;
    return 0;
}