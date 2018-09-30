#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Complex
    {
        friend Complex operator+(const Complex &a, const Complex &b);
        friend Complex operator*(const Complex &a, const Complex &b);
    private:
        int real;
        int img;
    public:
        Complex(int r = 0, int i = 0);
        Complex(const Complex &c);
        void display();
    };


#endif // COMPLEX_H_INCLUDED
