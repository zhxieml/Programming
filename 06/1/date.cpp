#include <iostream>
#include "date.h"
using namespace std;


const int Date::leapMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};   // Set the months;
const int Date::normalMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool operator>(const Date &d1, const Date &d2)
{
    if (d1.year > d2.year) return true;
    if (d1.year < d2.year) return false;
    if (d1.month > d2.month) return true;
    if (d1.month < d2.month) return false;
    if (d1.day > d2.day) return true;
    return false;
}

bool operator<(const Date &d1, const Date &d2)
{
    if (d1.year < d2.year) return true;
    if (d1.year > d2.year) return false;
    if (d1.month < d2.month) return true;
    if (d1.month > d2.month) return false;
    if (d1.day < d2.day) return true;
    return false;
}

ostream &operator<<(ostream &os, const Date &obj)
{
    char *month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
    "November", "December"};
    os << month_name[obj.month - 1] << " " << obj.day << ", " << obj.year;
    return os;
}

Date::Date(int m, int d, int y): year(y), month(m), day(d)
{
    if ((m <= 0 || m > 12) && ((d <= 0) || (isLeap() && d > leapMonth[m - 1]) || (!isLeap() && d > normalMonth[m - 1])))
    {
        year = 1990;    // If invalid, reset;
        month = 1;
        day = 1;
    }
}

Date & Date::operator++()
{
    int tmp = month;
    if (isLeap())
    {
        month += day / leapMonth[month - 1];    // day++ included already;
        day = day % leapMonth[tmp - 1] + 1;
        year += (month - 1)  / 12;
        month = (month - 1) % 12 + 1;
    }
    else
    {

        month += day / normalMonth[month - 1];
        day = day % normalMonth[tmp - 1] + 1;
        year += (month - 1)  / 12;
        month = (month - 1) % 12 + 1;
    }
    return *this;
}

Date Date::operator++(int)
{
    Date tmp = *this;
    if (isLeap())
    {
        month += day / leapMonth[month - 1];    // day++ already included;
        day = day % leapMonth[month - 1] + 1;
        year += (month - 1)  / 12;
        month = (month - 1) % 12;
    }
    else
    {
        month += day / normalMonth[month - 1];
        day = day % normalMonth[month - 1] + 1;
        year += (month - 1)  / 12;
        month = (month - 1) % 12 + 1;
    }
    return tmp;
}

Date & Date::operator+=(int n)
{
    while (n > 0)
    {
        if (isLeap()) n-=leapMonth[month - 1];  // Jump to the next month;
        else n -= normalMonth[month - 1];
        month ++;
        if (month > 12) // Reset the month if out of scope;
        {
            year++;
            month = 1;
        }
        if (isLeap())   // Reset the day if out of scope;
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
        if (month > 12) // Reset the month if out of scope;
        {
            year++;
            month = 1;
        }
    }
    if (isLeap())   // Add the rest of days;
    {
        if ((-1) * n >= day)
        {
            month -= 1;
            if (month < 1)
            {
                year--;
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
                month = 12;
            }
            day = normalMonth[month - 1] - ((-1) * n - day);
        }
        else day -= (-1) * n;
    }
    return *this;
}

bool Date::isLeap() const
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void Date::setDate(int m, int d, int y)
{
    year = y;
    month = m;
    day = d;
}
