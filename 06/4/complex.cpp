#include <iostream>
#include "complex.h"
using namespace std;

Complex::Complex(const char *r, const char *i): real(r), img(i){}

Complex::Complex(LongLongInt l1, LongLongInt l2): real(l1), img(l2){}

Complex::Complex(const Complex &c)
{
    real = c.real;
    img = c.img;
}

ostream &operator<<(ostream &os, const Complex &obj)
{
    os << obj.real << "+" << obj.img << "i";
    return os;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.img + c2.img);
}
