#include <iostream>
#include <cstring>
#include "LongLongInt.h"
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

void LongLongInt::add(LongLongInt a, LongLongInt b)
{
    int max_length = a.length > b.length ? a.length : b.length;
    int min_length = a.length < b.length ? a.length : b.length;
    length = max_length + 1;    // 1 more reserved for carry-over;
    storage = new int [length];
    int carry = 0;
    for (int i = 0; i < min_length; i++)
    {
        storage[i] = (a.storage[i] + b.storage[i] + carry) % 10;
        carry = (a.storage[i] + b.storage[i] + carry) / 10;
    }
    for (int i = min_length; i < max_length; i++)
    {
        if (a.length > b.length)
        {
            storage[i] = (a.storage[i] + carry) % 10;
            carry = (a.storage[i] + carry) / 10;
        }
        else
        {
            storage[i] = (b.storage[i] + carry) % 10;
            carry = (b.storage[i] + carry) / 10;
        }
    }
    storage[length - 1] = carry;
}

void LongLongInt::display()
{
    int i;
    for (i = length - 1; storage[i] == 0; i--);
    for (int j = i; j >= 0; j--)
    {
        cout << storage[j];
    }
}

LongLongInt::~LongLongInt()
{
    delete [] storage;
}
