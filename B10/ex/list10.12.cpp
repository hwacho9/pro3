#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    // 整数ベクトルa=(122519 304)
    std::vector<int> a;
    a.push_back(12);
    a.push_back(25);
    a.push_back(1);
    a.push_back(9);
    a.push_back(30);
    a.push_back(4);
    // 昇順にソート
    sort(a.begin(), a.end());

    // 降順ソート
    //  sort(a.begin(), a.end(), std::greater<int>());
    //  結果の表示

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}