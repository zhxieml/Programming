#include "signed_longlongint.h"
#include <iostream>
#include <cstring>
using namespace std;

void SignedLongLongInt::trans()
{
    char *tmp;
    sign = '+';
    tmp = signednumber;

    if (signednumber[0] == '-')
    {
        sign = '-';
        tmp = &signednumber[1];
    }

    if (signednumber[0] == '+')
    {
        tmp = &signednumber[1];
    }

    length = strlen(tmp);
    storage = new char[length];
    for (int i = length - 1; i >= 0; i--) storage[length - i - 1] = tmp[i];
}

SignedLongLongInt::SignedLongLongInt(char *num): signednumber(num)
{
    trans();
}

SignedLongLongInt::SignedLongLongInt(const SignedLongLongInt &slli)
{
    signednumber = slli.signednumber;
    trans();
}

ostream &operator<<(ostream &os, const SignedLongLongInt &obj)
{
    if (obj.sign == '-') os << '-';
    os << (LongLongInt &)obj;
    return os;
}

istream &operator>>(istream &is, SignedLongLongInt &obj)
{
    delete [] obj.signednumber;
    obj.signednumber = new char[100];   // There may be a better way;
    is >> obj.signednumber;
    obj.trans();
    return is;
}

SignedLongLongInt operator+(const SignedLongLongInt &a, const SignedLongLongInt &b)
{
    SignedLongLongInt tmp;
    LongLongInt &tmp2 = tmp;
    if (a.sign == b.sign)
    {
        tmp2 = ((LongLongInt &)a + (LongLongInt &)b);
        tmp.sign = a.sign;
        return tmp;
    }

    int flag = a.length > b.length ? 1 : 2;
    if (a.length == b.length)
    {
        for (int i = a.length - 1; i >= 0; i--)
        {
            if (a.storage[i] > b.storage[i])
            {
                flag = 1;
                break;
            }
            if (a.storage[i] < b.storage[i])
            {
                flag = 2;
                break;
            }
        }
    }

    switch (flag)
    {
    case 1:
        tmp2 = ((LongLongInt &)a - (LongLongInt &)b);
        tmp.sign = a.sign;
        break;
    case 2:
        tmp2 = ((LongLongInt &)b - (LongLongInt &)a);
        tmp.sign = b.sign;
        break;
    }
    return tmp;
}

SignedLongLongInt operator-(const SignedLongLongInt &a, const SignedLongLongInt &b)
{
    SignedLongLongInt tmp;
    LongLongInt &tmp2 = tmp;
    if (a.sign != b.sign)
    {
        tmp2 = ((LongLongInt &)a + (LongLongInt &)b);
        tmp.sign = a.sign;
        return tmp;
    }

    int flag = a.length > b.length ? 1 : 2;
    if (a.length == b.length)
    {
        for (int i = a.length - 1; i >= 0; i--)
        {
            if (a.storage[i] > b.storage[i])
            {
                flag = 1;
                break;
            }
            if (a.storage[i] < b.storage[i])
            {
                flag = 2;
                break;
            }
        }
    }

    switch (flag)
    {
    case 1:
        tmp2 = ((LongLongInt &)a - (LongLongInt &)b);
        tmp.sign = a.sign;
        break;
    case 2:
        tmp2 = ((LongLongInt &)b - (LongLongInt &)a);
        if (a.sign == '+') tmp.sign = '-';
        else tmp.sign = '+';
        break;
    }
    return tmp;
}

SignedLongLongInt::~SignedLongLongInt()
{
    delete [] signednumber;
}
