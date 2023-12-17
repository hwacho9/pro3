#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> int_vector;
typedef int_vector::iterator int_vector_iter;

int main(void)
{
    // 整数ベクトルvec=(352323)を作る
    int_vector vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << ">";
    int i;
    std::cin >> i;
    // ベクトル中のiを検索
    int_vector_iter p = find(vec.begin(), vec.end(), i);
    if (p == vec.end())
    {
        // 見つからない場合
        std::cout << "not found\n";
    }
    else
    {
        // 見つかった場合
        std::cout << *p << " found\n";
        // 見つかったところの直後から更に検索を継続
        p = find(++p, vec.end(), i);
        if (p == vec.end())
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
