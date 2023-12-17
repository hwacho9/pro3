#include <iostream>
#include <string>
#include <list>

class Record
{
public:
    int id;
    std::string name;
    int score;
    Record() {}
    Record(int i, const std::string &nm, int s)
    {
        id = i;
        name = nm;
        score = s;
    }
};

std::ostream &operator<<(std::ostream &os, const Record &r)
{
    os << "[" << r.id << "] " << r.name << " : " << r.score;
    return os;
}

class Seiseki
{
public:
    std::list<Record> data;
    void insert(int, const std::string &, int);
    void lookup(int) const;
    void erase_worst();
};

std::ostream &operator<<(std::ostream &os, const Seiseki &s)
{
    os << "*** 成績簿 ***\n";
    for (std::list<Record>::const_iterator it = s.data.begin(); it != s.data.end(); ++it)
    {
        os << *it << "\n";
    }
    return os;
}

void Seiseki::insert(int id, const std::string &nm, int s)
{
    // 挿入すべき位置を見つけてデータを挿入
    std::list<Record>::iterator it = data.begin();
    while (it != data.end() && it->id < id)
    {
        ++it;
    }
    data.insert(it, Record(id, nm, s));
}

void Seiseki::lookup(int id) const
{
    // 学生番号がidのデータを検索し出力
    std::list<Record>::const_iterator it = data.begin();
    while (it != data.end())
    {
        if (it->id == id)
        {
            std::cout << *it << "\n";
            return;
        }
        ++it;
    }
    std::cout << "not found\n";
}

void Seiseki::erase_worst()
{
    if (data.empty())
    {
        return; // 데이터가 없는 경우 아무 것도 하지 않음
    }

    // 최저 점수를 찾기
    int minScore = data.front().score;
    for (std::list<Record>::iterator it = data.begin(); it != data.end(); ++it)
    {
        if (it->score < minScore)
        {
            minScore = it->score;
        }
    }

    // 삭제해야 할 요소를 찾아서 삭제
    std::list<Record> toErase;
    for (std::list<Record>::iterator it = data.begin(); it != data.end();)
    {
        if (it->score == minScore)
        {
            toErase.push_back(*it);
            it = data.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // 기록된 요소를 출력하고 삭제
    for (std::list<Record>::const_iterator it = toErase.begin(); it != toErase.end(); ++it)
    {
        std::cout << "Erased: " << *it << "\n";
    }
}

int main(void)
{
    Seiseki s;

    // 성적 등록
    s.insert(7001, "aaaa", 89);
    s.insert(7123, "bbbb", 70);
    s.insert(7013, "cccc", 55);
    s.insert(7200, "dddd", 99);
    s.insert(7087, "eeee", 83);

    // 모든 학생의 성적 표시
    std::cout << s;

    // 입력한 id의 기록 표시 (0을 입력할 때까지 반복)
    int id;
    std::cout << "> ";
    std::cin >> id;
    while (id != 0)
    {
        s.lookup(id);
        std::cout << "> ";
        std::cin >> id;
    }

    // 가장 낮은 점수의 학생 삭제
    s.erase_worst();

    // 모든 학생의 성적 표시
    std::cout << s;

    return 0;
}
