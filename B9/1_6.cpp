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
};

int main(void)
{
    Complex x, y, z, a;
    x = Complex(1.00, 2.00);
    y = Complex(2.22, 3.14);
    z = Complex(4.23, 9.99);
    a = x + y + z;
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