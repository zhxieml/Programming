#include <iostream>
#include "signed_longlongint.h"
using namespace std;

int main()
{
    SignedLongLongInt s1("+33"), s2("999"), s3, s4;
    cout << "a = " << s1 << endl;
    cout << "b = " << s2 << endl;
    s3 = s1 + s2;
    s4 = s1 - s2;
    cout << "a + b = " << s3 << endl;
    cout << "a - b = " << s4 << endl;

    SignedLongLongInt s5("-33"), s6("999"), s7, s8;
    cout << "c = " << s5 << endl;
    cout << "d = " << s6 << endl;
    s7 = s5 + s6;
    s8 = s5 - s6;
    cout << "c + d = " << s7 << endl;
    cout << "c - d = " << s8 << endl;

    SignedLongLongInt s;
    cout << "Please input an integer:";
    cin >> s;
    cout << "The integer you inputed is: " << s;
    return 0;
}
