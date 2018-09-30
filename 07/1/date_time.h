#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED
    #include "time.h"
    #include "date.h"
    #include <iostream>
    using namespace std;

    class DateTime: public Date, public Time
    {
        friend ostream &operator<<(ostream &os, const DateTime &obj);
        friend istream &operator>>(istream &is, DateTime &obj);
    private:
        bool checkTimeValid() const;
    public:
        DateTime(int mon = 1, int da = 1, int ye = 1990, int s = 0, int m = 0, int h = 0);
        void showDate() const;
        void showTime() const;
        void setDate();
        void setTime();
    };


#endif // DATE_TIME_H_INCLUDED
