#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> s;
    s.push_back(5);
    s.push_back(7);
    s.push_back(9);
    s.push_back(11);
    // s= (5 7 9 11)

    std::cout << "size = " << s.size() << std::endl; // size=4
    for (int i = 0; i < s.size(); i++)
    {
        std ::cout << s[i] << " ";
    }
    std::cout << std::endl;
    std::cout << s.back() << std::endl;              // 11
    s.pop_back();                                    // s =(579)
    std::cout << s.back() << std::endl;              // 9
    s.pop_back();                                    // s =(57)
    std::cout << "size = " << s.size() << std::endl; // size=2
    for (int i = 0; i < s.size(); i++)
    {
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}