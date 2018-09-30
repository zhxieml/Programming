// File: date.cpp
// This file includes the definition of all the functions.

#include "date.h"
#include <iostream>
#include <cstring>
using namespace std;

// Function: checkValid
// Check whether the object is valid or not
// If the date format is not legal, return false. Otherwise, return true
bool Date::checkValid()
{
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (year > 9999 || month > 12 ||
        (isLeap && day > leapMonth[month - 1] || !isLeap && day > normalMonth[month - 1])) return false;
    return true;
}

// Function: create
// Create an Date object with the given date in string type
bool Date::create(char *date)
{
    year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
    month = (date[4] - '0') * 10 + (date[5] - '0');
    day = (date[6] - '0') * 10 + (date[7] - '0');
    return checkValid();
}

// Function: n_days_after
// Refresh the Date object with the given n
// n: the number of days
bool Date::n_days_after(int n)
{
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    while (n > 0)
    {
        if (isLeap) n-=leapMonth[month - 1];
        else n -= normalMonth[month - 1];
        month ++;
        if (month > 12)
        {
            year++;
            isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
            month = 1;
        }
        if (isLeap)
        {
            if (day > leapMonth[month - 1])
            {
                day -= leapMonth[month - 1];
                month++;
            }
        }
        else
        {
            if (day > normalMonth[month - 1])
            {
                day -= normalMonth[month - 1];
                month++;
            }
        }
        if (month > 12)
        {
            year++;
            isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
            month = 1;
        }
    }
    if (isLeap)
    {
        if ((-1) * n >= day)
        {
            month -= 1;
            if (month < 1)
            {
                year--;
                isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
                month = 12;
            }
            day = leapMonth[month- 1] - ((-1) * n - day);
        }
        else day -= (-1) * n;
    }
    else
    {
        if ((-1) * n >= day)
        {
            month -= 1;
            if (month < 1)
            {
                year--;
                isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
                month = 12;
            }
            day = normalMonth[month - 1] - ((-1) * n - day);
        }
        else day -= (-1) * n;
    }
    return checkValid();
}

// Function: display
// Show the date
void Date::display()
{
    cout << "Date:" << year << "/" << month << "/" << day;
}
