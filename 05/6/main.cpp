#include <iostream>
#include "time.h"
using namespace std;

int main()
{
    Time t1(20, 20, 1), t2(70, 10, 3);
    cout << "t1:";
    t1.display();
    cout << endl << "t2:";
    t2.display();
    cout << endl << "After t1 += t2, t1:";
    t1 += t2;
    t1.display();
    cout << "\tt2:";
    t2.display();
    cout << endl << "After t1 = t2++, t1:";
    t1 = t2++;
    t1.display();
    cout << "\tt2:";
    t2.display();
    cout << endl << "After t1 = ++t2, t1:";
    t1 = ++t2;
    t1.display();
    cout << "\tt2:";
    t2.display();
    return 0;
}
