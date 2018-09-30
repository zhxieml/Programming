#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
    #include <iostream>
    #include "longlongint.h"
    using namespace std;

    class Complex
    {
        friend Complex operator+(const Complex &c1, const Complex &c2);
        friend ostream &operator<<(ostream &os, const Complex &obj);
    private:
        LongLongInt real;
        LongLongInt img;
    public:
        Complex(const char *r = "0", const char *i = "0");
        Complex(LongLongInt l1, LongLongInt l2);
        Complex(const Complex &c);
    };


#endif // COMPLEX_H_INCLUDED
