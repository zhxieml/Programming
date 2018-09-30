#ifndef LONGLONGINT_H_INCLUDED
#define LONGLONGINT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class LongLongInt
    {
        friend LongLongInt operator+(const LongLongInt &a, const LongLongInt &b);
        friend LongLongInt operator-(const LongLongInt &a, const LongLongInt &b);
        friend ostream &operator<<(ostream &os, const LongLongInt &obj);
        friend istream &operator>>(istream &is, LongLongInt &obj);
    protected:
        int length;
        char *storage;
    public:
        LongLongInt(char *num = "0");
        LongLongInt(const LongLongInt &lli);
        LongLongInt &operator=(const LongLongInt &lli);
        void trans();
        void getLength() const;
        ~LongLongInt();
    };


#endif // LONGLONGINT_H_INCLUDED
