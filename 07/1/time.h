#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Time
    {
        friend ostream &operator<<(ostream &os, const Time &obj);
        friend istream &operator>>(istream &is, Time &obj);
    protected:
        int hour;
        int minute;
        int second;
        void check();
    public:
        Time(int s = 0, int m = 0, int h = 0);
        Time(const Time &t);
        Time &operator++();
        Time operator++(int);
        Time &operator--();
        Time operator--(int);
        Time &operator+=(const Time &t);
        Time &operator-=(const Time &t);
    };


#endif // TIME_H_INCLUDED
