#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> a(5);
    std::cout << "a.size = " << a.size() << std::endl;
    // a.size = 5
    for (int i = 0; i < a.size(); i++)
        a[i] = i;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    // 0 1 2 3 4

    std::vector<int> b(3);
    b[0] = 7;
    b[1] = 5;
    b[2] = 3;

    std::vector<int> c(10);
    for (int i = 0; i < c.size(); i++)
        c[i] = i * i;

    a = b;
    std::cout << "a.size = " << a.size() << std::endl;
    // a.size = 3と表示
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    // 753と表示

    a = c;
    std::cout << "a.size = " << a.size() << std::endl;
    // a.size = 10と表示
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    // 014 9162536496481と表示

    a.resize(30);
    // a.size=30と表示
    std::cout << "a.size = " << a.size() << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    // 014 916253649648100 0...と表示

    return 0;
}