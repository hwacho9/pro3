#include <iostream>

stack plus(stack s1, stack s2)
{
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);
    while (!s2.empty())
    {
        tmp.push(s2.top());
        s2.pop();
    }
    while (!s1.empty())
    {
        tmp.push(s1.top());
        s1.pop();
    }
    while (!tmp.empty())
    {
        tmp.push(tmp.top());
        tmp.pop();
    }
    return s;
}

int main(void)
{

    stack s1(5);
    stack s2(5);
    stack s(10);

    s1.push(1);
    s1.push(3);
    s1.push(5);
    s1.push(2);
    s1.push(4);
    s1.push(6);

    s = plus(s1, s2);

    s1.dump(std::cout);
    s2.dump(std::cout);
    s.dump(std::cout);

    return 0;
}