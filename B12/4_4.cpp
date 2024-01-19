#include <iostream>

class stack
{
protected:
    int *st;
    int sp;
    int capacity;

public:
    stack(int max_size) : capacity(max_size)
    {
        st = new int[capacity];
        sp = 0;
    }

    ~stack()
    {
        delete[] st;
    }

    void push(int val)
    {
        if (sp < capacity)
        {
            st[sp++] = val;
        }
        else
        {
            std::cerr << "Stack overflow!" << std::endl;
        }
    }

    int pop()
    {
        if (sp > 0)
        {
            return st[--sp];
        }
        else
        {
            std::cerr << "Stack underflow!" << std::endl;
            return -1; // エラー
        }
    }

    int size() const
    {
        return sp;
    }
};

class stack_ac : public stack
{
private:
    int push_count;
    int pop_count;

public:
    stack_ac(int max_size) : stack(max_size), push_count(0), pop_count(0) {}

    ~stack_ac() {}

    void push(int val)
    {
        stack::push(val);
        push_count++;
    }

    void pop()
    {
        int result = stack::pop();
        if (result != -1)
        {
            pop_count++;
        }
    }

    int n_push() const
    {
        return push_count;
    }

    int n_pop() const
    {
        return pop_count;
    }
};

int main()
{
    stack_ac sa(5); // Creating stack_ac object with a capacity of 5

    sa.push(1);
    sa.push(2);
    sa.push(3);
    sa.pop();
    sa.push(4);

    std::cout << "Stack size: " << sa.size() << std::endl;
    std::cout << "Push count: " << sa.n_push() << std::endl;
    std::cout << "Pop count: " << sa.n_pop() << std::endl;

    return 0;
}
