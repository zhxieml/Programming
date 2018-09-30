#include <iostream>
#include <cstring>
#include "longlongint.h"
using namespace std;

LongLongInt::LongLongInt(const char *num)
{
    length = strlen(num);
    storage = new int[length];
    for (int i = length - 1; i >= 0; i--) storage[length - i - 1] = num[i] - '0';
}

LongLongInt::LongLongInt(const LongLongInt &lli)
{
    length = lli.length;
    storage = new int[length];
    for (int i = 0; i < length; i++) storage[i] = lli.storage[i];
}

LongLongInt operator+(const LongLongInt &a, const LongLongInt &b)
{
    int max_length = a.length > b.length ? a.length : b.length;
    int min_length = a.length < b.length ? a.length : b.length;
    LongLongInt l;
    l.length = max_length + 1;    // 1 more reserved for carry-over;
    l.storage = new int[l.length];
    int carry = 0;
    for (int i = 0; i < min_length; i++)
    {
        l.storage[i] = (a.storage[i] + b.storage[i] + carry) % 10;
        carry = (a.storage[i] + b.storage[i] + carry) / 10;
    }
    for (int i = min_length; i < max_length; i++)
    {
        if (a.length > b.length)
        {
            l.storage[i] = (a.storage[i] + carry) % 10;
            carry = (a.storage[i] + carry) / 10;
        }
        else
        {
            l.storage[i] = (b.storage[i] + carry) % 10;
            carry = (b.storage[i] + carry) / 10;
        }
    }
    l.storage[l.length - 1] = carry;
    return l;
}

ostream &operator<<(ostream &os, const LongLongInt &obj)
{
    int i;
    for (i = obj.length - 1; obj.storage[i] == 0; i--);
    for (int j = i; j >= 0; j--)
    {
        os << obj.storage[j];
    }
    return os;
}

LongLongInt &LongLongInt::operator=(const LongLongInt &lli)
{
    if (this == &lli) return *this;
    delete [] storage;
    length = lli.length;
    storage = new int[length];
    for (int i = 0; i < length; i++) storage[i] = lli.storage[i];
    return *this;
}

LongLongInt::~LongLongInt()
{
    delete [] storage;
}
