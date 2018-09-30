// File: main.cpp
// The main module to present the function

#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1(2.0, 2.0), c2(3.0, 2.0), c3;
    c3.add(c1, c2);
    c3.show();
    cout << endl;
    c3.multi(c1, c2);
    c3.show();
    return 0;
}
