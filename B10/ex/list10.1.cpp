#include <iostream>
#include <string>

int main(void)
{
    std::string message = "Enger strings";
    std::cout << message << ": ";
    std::string s;
    std::cin >> s;
    std::cout << "word 1 = " << s << std::endl;
    std::cin >> s;
    std::cout << "word 2 = " << s << std::endl;
    getline(std::cin, s);
    std::cout << "line = "
              << "'" << s << "'" << std::endl;
    getline(std::cin, s);
    std::cout << "line = "
              << "'" << s << "'" << std::endl;
    return 0;
}