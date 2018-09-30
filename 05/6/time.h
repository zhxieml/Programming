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
    public:
        Time(int s = 0, int m = 0, int h = 0);
        Time(const Time &t);
        Time &operator++();
        Time operator++(int);
        Time &operator--();
        Time operator--(int);
        Time &operator+=(const Time &t);
        Time &operator-=(const Time &t);
        void display();
        void check();
    };


#endif // TIME_H_INCLUDED
