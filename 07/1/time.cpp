#include <iostream>
#include "time.h"
using namespace std;

void Time::check()
{
    int sec = second + 60 * minute + 3600 * hour;
    hour = sec / 3600;
    minute = (sec - hour * 3600) / 60;
    second = sec - 60 * minute - 3600 * hour;
}

ostream &operator<<(ostream &os, const Time &obj)
{
    os << obj.hour << ":" << obj.minute << ":" << obj.second;
    return os;
}

istream &operator>>(istream &is, Time &obj)
{
    cout << "Please input the number of hour, minite and second:";
    is >> obj.hour >> obj.minute >> obj.second;
    obj.check();
    return is;
}

Time::Time(int s, int m, int h): second(s), minute(m), hour(h)
{
    check();
}

Time::Time(const Time &t)
{
    second = t.second;
    minute = t.minute;
    hour = t.hour;
}

Time & Time::operator++()
{
    second++;
    check();
    return *this;
}

Time Time::operator++(int)
{
    Time tmp = *this;
    second++;
    check();
    return tmp;
}

Time & Time::operator--()
{
    second--;
    check();
    return *this;
}

Time Time::operator--(int)
{
    Time tmp = *this;
    second--;
    check();
    return tmp;
}

Time & Time::operator+=(const Time &t)
{
    second += t.second;
    minute += t.minute;
    hour += t.hour;
    check();
    return *this;
}

Time & Time::operator-=(const Time &t)
{
    second -= t.second;
    minute -= t.minute;
    hour -= t.hour;
    check();
    return *this;
}
