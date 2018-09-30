#ifndef LONGLONGINT_H_INCLUDED
#define LONGLONGINT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class LongLongInt
    {
        friend LongLongInt operator+(const LongLongInt &a, const LongLongInt &b);
        friend ostream &operator<<(ostream &os, const LongLongInt &obj);
    private:
        int length;
        int *storage;
    public:
        LongLongInt(const char *num = "0");
        LongLongInt(const LongLongInt &lli);
        LongLongInt &operator=(const LongLongInt &lli);
        ~LongLongInt();
    };


#endif // LONGLONGINT_H_INCLUDED
