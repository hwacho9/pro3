#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }

    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    // 新しいコンストラクタ
    Complex(double r)
    {
        real = r;
        imag = 0.0;
    }

    Complex operator+(const Complex &other) const
    {
        double r = real + other.real;
        double i = imag + other.imag;
        return Complex(r, i);
    }

    ~Complex() {}

    double re() const { return real; }

    double im() const { return imag; }

    void set_re(double r) { real = r; }

    void set_im(double i) { imag = i; }

    void print(std::ostream &os) const
    {
        os << real << "+" << imag << "i";
    }

    Complex &operator=(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
        return *this;
    }

    // Addition assignment operator
    Complex &operator+=(const Complex &c)
    {
        real += c.real;
        imag += c.imag;
        return *this;
    }
};

int main(void)
{
    Complex x, y, z, a;
    x = Complex(1.00, 2.00);
    y = Complex(2.22, 3.14);
    z = Complex(4.23, 9.99);

    // 新しいコンストラクタを使用してComplexオブジェクトを初期化
    a = Complex(5.0);

    // Print initial values
    std::cout << "Initial values:" << std::endl;
    x.print(std::cout);
    std::cout << std::endl;

    y.print(std::cout);
    std::cout << std::endl;

    z.print(std::cout);
    std::cout << std::endl;

    a.print(std::cout);
    std::cout << std::endl;

    // Use assignment operator
    x = y;

    // Use addition assignment operator
    z += x;

    // Print updated values
    std::cout << "\nAfter assignment and addition:" << std::endl;
    x.print(std::cout);
    std::cout << std::endl;

    y.print(std::cout);
    std::cout << std::endl;

    z.print(std::cout);
    std::cout << std::endl;

    a.print(std::cout);
    std::cout << std::endl;

    return 0;
}
