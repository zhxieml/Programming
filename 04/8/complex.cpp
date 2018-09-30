// File: complex.cpp
// This file includes the definition of all the functions

#include "complex.h"
#include <iostream>
using namespace std;

// Function: Complex
// The cpnstructor
Complex::Complex(double r, double i)
{
    real = r;
    img = i;
}

// Function: add
// Add two complex numbers
void Complex::add(const Complex &c1, const Complex &c2)
{
    real = c1.real + c2.real;
    img = c1.img + c2.img;
}

// Function: multi
// Multiply two complex numbers
void Complex::multi(const Complex &c1, const Complex &c2)
{
    real = c1.real * c2.real + c1.img * c2.img;
    img = c1.real * c2.img + c1.img * c2.real;
}

// Function: show
// Show the complex
void Complex::show()
{
    cout << real << " + " << img << "i";
}
