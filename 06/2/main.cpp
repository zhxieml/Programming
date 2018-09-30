#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector v1(3), v2(3);
    cout << "The number of vectors created is: " << Vector::createN() << endl;
    cout << "The number of vectors living is: " << Vector::livingN() << endl;
    cin >> v1 >> v2;
    Vector v3 = v1 + v2;
    cout << "v3: " << v3 << endl;
    cout << "The value of v3 in dimension 2 is: " << v3[1] << endl;
    switch (v1 == v2)
    {
        case 1: cout << "v1 == v2" << endl;
        default: cout << "v1 != v2" << endl;
    }
    cout << "v1++= " << v1++ << endl;
    cout << "v2--= " << v2-- << endl;
    double d = v1;
    cout << "The length of v1 is: " << d << endl;
    {
        Vector v(5);
    }
    cout << "The number of vectors created is: " << Vector::createN() << endl;
    cout << "The number of vectors living is: " << Vector::livingN() << endl;
    v1.displayDim();
    return 0;
}
