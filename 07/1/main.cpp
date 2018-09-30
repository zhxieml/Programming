#include <iostream>
#include "date_time.h"
using namespace std;

int main()
{
    DateTime dt1(5, 23, 2018, 59, 59, 11);
    cout << "The date and time is: " << dt1 << endl;
    cout << "The date is: ";
    dt1.showDate();
    cout << endl;
    cout << "The time is: ";
    dt1.showTime();
    cout << endl;

    dt1.setDate();
    dt1.setTime();
    cout << "The date and time is: " << dt1 << endl;
    return 0;
}
