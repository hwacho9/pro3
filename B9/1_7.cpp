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
    Complex operator-(const Complex &other) const
    {
        double r = real - other.real;
        double i = imag - other.imag;
        return Complex(r, i);
    }

    Complex operator*(const Complex &other) const
    {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
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

std::ostream &operator<<(std::ostream &os, Complex &c)
{
    c.print(os);
    return os;
}
int main(void)
{
    Complex a(1.00, 2.00);
    Complex b(3.00, 4.00);
    Complex c(2.35, 5.32);
    Complex s = c - b;
    s.print(std::cout);
    std::cout << std::endl;
    Complex t = a * b;
    t.print(std::cout);
    std::cout << std::endl;

    return 0;
}