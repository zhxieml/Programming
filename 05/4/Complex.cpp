#include <iostream>
#include "Complex.h"
using namespace std;

Complex operator+(const Complex &a, const Complex &b)
{
    Complex c;
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

Complex operator*(const Complex &a, const Complex &b)
{
    Complex c;
    c.real = a.real * b.real + a.img * b.img;
    c.img = a.img + b.real + a.real * b.img;
    return c;
}

Complex::Complex(int r, int i): real(r), img(i){}

Complex::Complex(const Complex &c)
{
    real = c.real;
    img = c.img;
}

void Complex::display()
{
    if (img != 1) cout << real << "+" << img << "i";
    else cout << real << "+i";

}
