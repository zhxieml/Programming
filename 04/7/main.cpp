// File: main.cpp
// The main module to present the functions.

#include <iostream>
#include <cstring>
#include "date.h"
using namespace std;

int main()
{
    Date date1;
    char date[9];
    int n;
    cout << "Please input the date with the format of 'XXXXYYZZ'(year/month/day):";
    cin >> date;
    int len = strlen(date);
    if (len != 8 || !date1.create(date))
    {
        cout << "Illegal date format!" << endl;
        return -1;
    }
    cout << "How many days do you want to move forward?";
    cin >> n;

    if (date1.n_days_after(n))
    {
        cout << "After " << n << " days:" << endl;
        date1.display();
    }
    else
    {
        cout << "Out of limitation!";
        return -1;
    }
    return 0;
}
