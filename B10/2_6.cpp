#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

// 名前で比較する関数オブジェクト
struct CompareByName
{
    bool operator()(const Entry &a, const Entry &b) const
    {
        return a.name < b.name;
    }
};

// 電話番号で比較する関数オブジェクト
struct CompareByPhone
{
    bool operator()(const Entry &a, const Entry &b) const
    {
        return a.phone < b.phone;
    }
};

int main(void)
{
    std::vector<Entry> entries;

    entries.push_back(Entry("Kwansei Gakuin University (PR)", "0798-54-6017"));
    entries.push_back(Entry("Kwansei Gakuin University (KSC)", "079-565-7600"));
    entries.push_back(Entry("Kobe University", "078-881-1212"));
    entries.push_back(Entry("Sanda Woodytown SATY", "079-564-8800"));
    entries.push_back(Entry("Sanda Hotel", "079-564-1101"));

    // 名前順にソート
    std::sort(entries.begin(), entries.end(), CompareByName());

    std::cout << "名前順にソート:\n";
    for (size_t i = 0; i < entries.size(); ++i)
    {
        // 電話番号"079-xxx-xxxx"を"xxx-xxxx"にする
        size_t hyphenPos = entries[i].phone.find('-');
        if (hyphenPos != std::string::npos)
        {
            entries[i].phone.erase(0, hyphenPos + 1);
        }

        std::cout << entries[i] << std::endl;
    }

    // 電話番号順にソート
    std::sort(entries.begin(), entries.end(), CompareByPhone());

    std::cout << "\n電話番号順にソート:\n";
    for (size_t i = 0; i < entries.size(); ++i)
    {
        std::cout << entries[i] << std::endl;
    }

    return 0;
}
