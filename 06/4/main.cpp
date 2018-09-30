#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1("9999999999999999999", "22"), c2("22", "9999999999999999999999"), c3;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    return 0;
}
