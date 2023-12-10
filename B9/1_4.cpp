#include <iostream>
#include <assert.h>

class stack
{
private:
    const int max;
    int *data;
    int sp;

public:
    void push(int d)
    {
        assert(sp < max);
        data[sp++] = d;
    }
    void pop()
    {
        assert(0 < sp);
        --sp;
    }
    bool empty() const
    {
        return sp == 0;
    }
    int top() const
    {
        return data[sp - 1];
    }

    int size() const
    {
        return sp;
    }
    stack(int sz = 100) : max(sz)
    {
        std::cout << "Max size of the stack: " << max << std::endl;
        sp = 0;
        data = new int[max];
    }
    ~stack() { delete[] data; }
};

int main(void)
{
    stack s(45);
    s.push(5);
    s.push(8);
    s.push(9);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    s.push(3);
    std::cout << s.size() << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}