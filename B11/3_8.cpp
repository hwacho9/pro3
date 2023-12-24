#include <iostream>
#include <cassert>

class stack
{
private:
    int sp;
    int max;
    int *data;

public:
    stack(int sz)
    {
        sp = 0;
        max = sz;
        data = new int[max];
    }

    // Copy constructor
    stack(const stack &other)
    {
        max = other.max;
        sp = other.sp;
        data = new int[max];

        // Copy elements from other.data to data
        for (int i = 0; i < sp; ++i)
        {
            data[i] = other.data[i];
        }
    }

    ~stack() { delete[] data; }

    void push(int d)
    {
        assert(sp < max);
        data[sp++] = d;
    }

    void pop()
    {
        assert(sp > 0);
        --sp;
    }

    bool empty() const { return sp == 0; }

    int top() const
    {
        assert(!empty());
        return data[sp - 1];
    }

    int size() const { return sp; }

    void dump(std::ostream &os) const;
};

void stack::dump(std::ostream &os) const
{
    os << "max=" << max << ", ";
    os << "sp=" << sp << ", ";
    os << "data=(";
    for (int i = 0; i < sp; i++)
        os << data[i] << " ";
    os << ")" << std::endl;
}

// Updated plus function to use references
stack plus(const stack &s1, const stack &s2)
{
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);

    // Copy elements from s2 to tmp
    stack tmpS2(s2);
    while (!tmpS2.empty())
    {
        tmp.push(tmpS2.top());
        tmpS2.pop();
    }

    // Copy elements from s1 to tmp
    stack tmpS1(s1);
    while (!tmpS1.empty())
    {
        tmp.push(tmpS1.top());
        tmpS1.pop();
    }

    return tmp;
}

int main(void)
{

    stack s1(5);
    s1.push(1);
    s1.push(3);
    s1.push(5);

    // Using the copy constructor to create a copy of s1
    stack s2(s1);

    // Dumping both stacks to verify the copy
    s1.dump(std::cout);
    s2.dump(std::cout);

    return 0;
}
