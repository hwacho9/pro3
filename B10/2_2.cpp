#include <iostream>
#include <string>
#include <vector>

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
    std::vector<Entry> entries;

    entries.push_back(Entry("Kwansei Gakuin University (PR)", "0798-54-6017"));
    entries.push_back(Entry("Kwansei Gakuin University (KSC)", "079-565-7600"));
    entries.push_back(Entry("Kobe University", "078-881-1212"));
    entries.push_back(Entry("Sanda Woodytown SATY", "079-564-8800"));
    entries.push_back(Entry("Sanda Hotel", "079-564-1101"));

    for (size_t i = 0; i < entries.size(); ++i)
    {
        // 電話番号"079-xxx-xxxx"を"xxx-xxxx"にする
        size_t hyphenPos = entries[i].phone.find('-');
        if (hyphenPos != std::string::npos)
        {
            entries[i].phone.erase(0, hyphenPos + 1);
        }

        // 出力
        std::cout << entries[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "検索用文字列を入力してください: ";
    std::string s;
    std::cin >> s;

    for (size_t i = 0; i < entries.size(); ++i)
    {
        // nameにsを含むデータを全て表示する
        if (entries[i].name.find(s) != std::string::npos)
        {
            std::cout << entries[i] << std::endl;
        }
    }

    return 0;
}
