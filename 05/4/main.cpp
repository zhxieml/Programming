#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a(1, 1), b(3, 2);
    Complex c;
    cout << "a=";
    a.display();
    cout << endl;
    cout << "b=";
    b.display();
    c = a + b;
    cout << endl;
    cout << "a+b=";
    c.display();
    c = a * b;
    cout << endl;
    cout << "a*b=";
    c.display();
    return 0;
}
