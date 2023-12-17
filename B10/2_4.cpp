#include <iostream>
#include <string>
#include <map>

class Entry
{
public:
    std::string name;
    std::string phone;
    Entry(const std::string &nm = "", const std::string &ph = "")
    {
        name = nm;
        phone = ph;
    }
};

std::ostream &operator<<(std::ostream &os, const Entry &e)
{
    os << e.name << ": " << e.phone;
    return os;
}

int main(void)
{
    std::map<std::string, Entry> phoneBook;

    phoneBook["Kwansei Gakuin University (PR)"] = Entry("Kwansei Gakuin University (PR)", "0798-54-6017");
    phoneBook["Kwansei Gakuin University (KSC)"] = Entry("Kwansei Gakuin University (KSC)", "079-565-7600");
    phoneBook["Kobe University"] = Entry("Kobe University", "078-881-1212");
    phoneBook["Sanda Woodytown SATY"] = Entry("Sanda Woodytown SATY", "079-564-8800");
    phoneBook["Sanda Hotel"] = Entry("Sanda Hotel", "079-564-1101");

    for (std::map<std::string, Entry>::iterator it = phoneBook.begin(); it != phoneBook.end(); ++it)
    {
        // 전화번호 "079-xxx-xxxx"를 "xxx-xxxx"로 변경
        size_t hyphenPos = it->second.phone.find('-');
        if (hyphenPos != std::string::npos)
        {
            it->second.phone.erase(0, hyphenPos + 1);
        }

        // 출력
        std::cout << it->second << std::endl;
    }

    std::cout << std::endl;
    std::cout << "検索用文字列を入力してください: ";
    std::string searchName;
    std::cin >> searchName;

    // 이름에 searchName이 포함하는 데이터를 찾아 출력
    for (std::map<std::string, Entry>::iterator it = phoneBook.begin(); it != phoneBook.end(); ++it)
    {
        if (it->first.find(searchName) != std::string::npos)
        {
            // 전화번호 "079-xxx-xxxx"를 "xxx-xxxx"로 변경
            size_t hyphenPos = it->second.phone.find('-');
            if (hyphenPos != std::string::npos)
            {
                it->second.phone.erase(0, hyphenPos + 1);
            }

            std::cout << "Result : " << it->second << std::endl;
        }
    }

    return 0;
}
