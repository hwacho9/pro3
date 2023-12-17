#include <iostream>
#include <map>
#include <string>
int main(void)
{
    std::map<std::string, int> semester;
    semester["logiccircuits"] = 1;
    semester["compiler"] = 5;
    semester["formallanguageandautomata"] = 3;
    std::cout << semester["logiccircuits"] << "\n";
    std::cout << semester["compiler"] << "\n";
    std::cout << semester["network"] << "\n";

    std::map<std::string, int>::iterator p;
    for (p = semester.begin(); p != semester.end(); p++)
    {
        std::cout << p->first << ": " << p->second << std::endl;
    }

    std::string s;
    std::cout << ">";
    std::cin >> s;
    if ((p = semester.find(s)) == semester.end())
    {
        std::cout << s << " not found" << std::endl;
    }
    else
    {
        std::cout << "deleting" << p->first << std::endl;
        semester.erase(p);
    }

    return 0;
}