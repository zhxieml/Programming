// File: time.h
// The head file of the class Time.

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Time
    {
    private:
        int hour;
        int minute;
        int second;
        void change();
    public:
        Time(int s = 0, int m = 0, int h = 0);
        void show();
    };


#endif // TIME_H_INCLUDED
