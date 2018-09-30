#ifndef SIGNED_LONGLONGINT_H_INCLUDED
#define SIGNED_LONGLONGINT_H_INCLUDED
    #include "longlongint.h"
    using namespace std;

    class SignedLongLongInt:public LongLongInt
    {
        friend SignedLongLongInt operator+(const SignedLongLongInt &a, const SignedLongLongInt &b);
        friend SignedLongLongInt operator-(const SignedLongLongInt &a, const SignedLongLongInt &b);
        friend ostream &operator<<(ostream &os, const SignedLongLongInt &obj);
        friend istream &operator>>(istream &is, SignedLongLongInt &obj);
    private:
        char *signednumber;
        char sign;
    public:
        SignedLongLongInt(char *num = "0");
        SignedLongLongInt(const SignedLongLongInt &slli);
        ~SignedLongLongInt();
        void trans();
    };
#endif // SIGNED_LONGLONGINT_H_INCLUDED
