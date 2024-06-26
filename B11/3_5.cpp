#include <iostream>
#include <string>
#include <cassert>

class stack
{
private:
    int sp;
    int max;
    int *data;

public:
    stack &operator=(const stack &);
    stack(int sz)
    {
        sp = 0;
        max = sz;
        data = new int[max];
    }

    ~stack() { delete[] data; }

    void push(int d)
    {
        assert(sp <= max);
        data[sp++] = d;
    }

    void pop()
    {
        assert(0 < sp);
        --sp;
    }

    bool empty() const { return sp == 0; }

    int top() const { return data[sp - 1]; }

    int size() const { return sp; }

    void dump(std::ostream &) const;
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

// Private assignment operator definition (not accessible from external code)
stack &stack::operator=(const stack &s)
{
    if (&s != this)
    {
        if (max < s.sp)
        {
            // Delete existing data
            delete[] data;
            data = new int[max = s.max];
        }
    }

    // Copy values
    sp = s.sp;

    // Copy data
    for (int i = 0; i < sp; i++)
        data[i] = s.data[i];

    return *this;
}

int main(void)
{
    stack s1(5), s2(7);

    s1.push(1);
    s1.push(3);
    s1.push(5);
    s2 = s1;
    s1.pop();
    s1.pop();
    s1.push(300);
    s1.push(500);
    s1.dump(std::cout);
    s2.dump(std::cout);
    return 0;
}
