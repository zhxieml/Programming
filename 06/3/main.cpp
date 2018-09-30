#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    Matrix m1(2, 3), m2(3, 2), m3(2, 3), m4;
    cout << "Input m1: " << endl;
    cin >> m1;
    cout << "Input m2: " << endl;
    cin >> m2;
    m3 = m1 * m2;
    cout << "m1 * m2: " << endl;
    cout << m1 * m2;
    cout << "m1:" << endl << m1;
    cout << "m2:" << endl << m2;
    cout << "m1 * m2:" << endl << m1 * m2;
    cout << "m1 transposed: " << endl;
    m1.transpose();
    cout << m1;
    return 0;
}
