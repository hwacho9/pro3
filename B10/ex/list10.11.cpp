#include <iostream>
#include <list>
#include <algorithm>

typedef std::list<int> int_list;
typedef int_list::iterator int_list_iter;

int main(void)
{
    // 整数リストli=(352323)を作る
    int_list li;
    li.push_back(3);
    li.push_back(5);
    li.push_back(2);
    li.push_back(3);
    li.push_back(2);
    li.push_back(3);

    std::cout << ">";
    int i;
    std::cin >> i;
    // リスト中のiを検索
    int_list_iter p = find(li.begin(), li.end(), i);
    if (p == li.end())
    {
        // 見つからない場合
        std::cout << "not found\n";
    }
    else
    {
        // 見つかった場合
        std::cout << *p << " found\n";
        // 見つかったところの直後から更に検索を継続
        p = find(++p, li.end(), i);
        if (p == li.end())
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *p << " found again\n";
        }
    }
    return 0;
}