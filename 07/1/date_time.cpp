#include "date_time.h"
#include <iostream>
using namespace std;

DateTime::DateTime(int mon, int da, int ye, int s, int m, int h): Date(mon, da, ye), Time(s, m, h)
{
    if (!checkTimeValid())
    {
        cout << "Invalid time! The time has been initialized as 00:00:00." << endl;
        hour = 0;
        minute = 0;
        second = 0;
    }
}

ostream &operator<<(ostream &os, const DateTime &obj)
{
    os << (Time &)obj << " on " << (Date &)obj;
    return os;
}

istream &operator>>(istream &is, DateTime &obj)
{
    int h = obj.hour, m = obj.minute, s = obj.second;
    is >> (Date &)obj >> (Time &)obj;
    if (!obj.checkTimeValid())
    {
        cout << "Invalid time! The time has been initialized as 00:00:00." << endl;
        obj.hour = h;
        obj.minute = m;
        obj.second = s;
    }
    return is;
}

void DateTime::showDate() const
{
    cout << (Date &)*this;
}

void DateTime::showTime() const
{
    int h = hour, m = minute, s = second;
    cout << (Time &)*this;
}

void DateTime::setDate()
{
//    int m = month, d = day, y = year;
    cin >> (Date &)*this;
//    if (!checkValid())
//    {
//        cout << "Invalid Date!" << endl;
//        month = m;
//        day = d;
//        year = y;
//    }
}

void DateTime::setTime()
{
    int h = hour, m = minute, s = second;
    cin >> (Time &)*this;
    if (!checkTimeValid())
    {
        cout << "Invalid time!" << endl;
        hour = h;
        minute = m;
        second = s;
    }
}

bool DateTime::checkTimeValid() const   // Check whether the time of the day is valid;
{
    if (hour >= 24) return false;
    else return true;
}

