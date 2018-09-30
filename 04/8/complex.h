// File: complex.h
// The head file of the class Complex.

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Complex
    {
    private:
        double real;
        double img;
    public:
        Complex(double r = 0.0, double i = 0.0);
        void add(const Complex &c1, const Complex &c2);
        void multi(const Complex &c1, const Complex &c2);
        void show();
    };


#endif // COMPLEX_H_INCLUDED
