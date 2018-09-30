#include <iostream>
#include <cstring>
#include "longlongint.h"
#include "assert.h"
using namespace std;

LongLongInt::LongLongInt(char *num)
{
    length = strlen(num);
    storage = new char[length];
    for (int i = length - 1; i >= 0; i--) storage[length - i - 1] = num[i];
}

LongLongInt::LongLongInt(const LongLongInt &lli)
{
    length = lli.length;
    storage = new char[length];
    for (int i = length - 1; i >= 0; i--) storage[length - i - 1] = lli.storage[length - i - 1];
}

LongLongInt operator+(const LongLongInt &a, const LongLongInt &b)
{
    LongLongInt l;
    int max_length = a.length > b.length ? a.length : b.length;
    int min_length = a.length < b.length ? a.length : b.length;

    char *tmp;
    tmp = new char[max_length + 2];

    int carry = 0;
    for (int i = 0; i < min_length; i++)
    {
        tmp[i] = (a.storage[i] - '0' + b.storage[i] - '0' + carry) % 10 + '0';
        carry = (a.storage[i] - '0' + b.storage[i] - '0' + carry) / 10;
    }
    for (int i = min_length; i < max_length; i++)
    {
        if (a.length > b.length)
        {
            tmp[i] = (a.storage[i] - '0' + carry) % 10 + '0';
            carry = (a.storage[i] - '0' + carry) / 10;
        }
        else
        {
            tmp[i] = (b.storage[i] - '0' + carry) % 10 + '0';
            carry = (b.storage[i] - '0' + carry) / 10;
        }
    }

    if (carry == 0) tmp[max_length] = '\0';
    else
    {
        tmp[max_length] = carry + '0';
        tmp[max_length + 1] = '\0';
    }

    l.length = strlen(tmp);
    l.storage = new char[l.length];
    strncpy(l.storage, tmp, l.length);
    delete [] tmp;
    return l;
}

LongLongInt operator-(const LongLongInt &a, const LongLongInt &b)
{
    LongLongInt l;
    assert(a.length >= b.length);
    if (a.length == b.length)
    {
        for (int i = a.length - 1; i >= 0; i--) assert(a.storage[i] >= b.storage[i]);
    }

    char *tmp;
    tmp = new char[a.length];

    int carry = 0;
    for (int i = 0; i < b.length; i++)
    {
        tmp[i] = (a.storage[i] - b.storage[i] + carry + 10) % 10 + '0';
        carry = a.storage[i] >= b.storage[i] ? 0 : -1;
    }

    for (int i = b.length; i < a.length; i++)
    {
        tmp[i] = (a.storage[i] - '0' + carry) % 10 + '0';
        carry = 0;
    }


    int countlen;
    for (countlen = a.length - 1; tmp[countlen] == '0'; countlen--){}

    l.length = countlen + 1;
    l.storage = new char[l.length];
    strncpy(l.storage, tmp, l.length);
    delete [] tmp;

    return l;
}

ostream &operator<<(ostream &os, const LongLongInt &obj)
{
    for (int i = obj.length - 1; i >= 0; i--)
    {
        os << obj.storage[i];
    }
    return os;
}

LongLongInt &LongLongInt::operator=(const LongLongInt &lli)
{
    if (this == &lli) return *this;
    delete [] storage;
    length = lli.length;
    storage = new char[length];
    for (int i = 0; i < length; i++) storage[i] = lli.storage[i];
    return *this;
}

LongLongInt::~LongLongInt()
{
    delete [] storage;
}

void LongLongInt::getLength() const
{
    cout << length;
}
