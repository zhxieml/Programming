#include <iostream>
#include "safeint.h"
#include <climits>
using namespace std;

int main()
{
    SafeInt s1(INT_MAX - 1), s2(0);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    try
    {
        cout << "s1 + s2 = " << s1 + s2 << endl;
        cout << "s1 - s2 = " << s1 - s2 << endl;
        cout << "s1 * s2 = " << s1 * s2 << endl;
        cout << "s1 / s2 = " << s1 / s2 << endl;
    }
    catch(Overflow)
    {
        cout << "Error! An Overflow has occured." << endl;
    }

    catch(DivByZero)
    {
        cout << "Error! An DivByZero has occured." << endl;
    }
    return 0;
}
