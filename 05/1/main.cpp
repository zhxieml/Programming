#include <iostream>
#include "LongLongInt.h"
using namespace std;

int main()
{
    char *a = "33";
    LongLongInt l1(a), l2("999999999999999999999");
    cout << "l1:";
    l1.display();
    cout << endl << "l2:";
    l2.display();
    LongLongInt l3;
    l3.add(l1, l2);
    cout << endl;
    cout << "l1 + l2:";
    l3.display();
    return 0;
}
