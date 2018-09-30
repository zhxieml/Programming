// File: time.cpp
// This file includes the definition of all the functions

#include "time.h"
#include <iostream>
using namespace std;

// Function: change
// Change the format
void Time::change()
{
    int s = hour * 3600 + minute * 60 + second;
    hour = s / 3600;
    minute = (s - hour * 3600) / 60;
    second = s - hour * 3600 - minute * 60;
}

// Function: change
// The constructor
Time::Time(int s, int m, int h): second(s), minute(m), hour(h)
{
    change();
}

// Function: show
// Show the time
void Time::show()
{
    cout << hour << "h" << minute << "m" << second << "s";
}
