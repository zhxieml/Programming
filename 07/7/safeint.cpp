#include "safeint.h"
#include <climits>
#include <iostream>
using namespace std;

SafeInt::SafeInt(int v): value(v){}

SafeInt::SafeInt(const SafeInt &s)
{
    value = s.value;
}

SafeInt operator+(const SafeInt &s1, const SafeInt &s2) throw(Overflow)
{
    if ((s1.value > INT_MAX - s2.value && s2.value > 0) || (s1.value < INT_MIN - s2.value && s2.value < 0)) throw Overflow();
    return SafeInt(s1.value + s2.value);
}

SafeInt operator-(const SafeInt &s1, const SafeInt &s2) throw(Overflow)
{
    if ((s1.value > INT_MAX + s2.value && s2.value < 0) || (s1.value < INT_MIN + s2.value && s2.value > 0)) throw Overflow();
    return SafeInt(s1.value - s2.value);
}

SafeInt operator*(const SafeInt &s1, const SafeInt &s2) throw(Overflow)
{
    if (s2.value > 1 && (s1.value > static_cast<double>(INT_MAX) / s2.value || s1.value < static_cast<double>(INT_MIN) / s2.value)) throw Overflow();
    if (s2.value < -1 && (s1.value < static_cast<double>(INT_MAX) / s2.value || s1.value > static_cast<double>(INT_MIN) / s2.value)) throw Overflow();
    return SafeInt(s1.value * s2.value);
}

SafeInt operator/(const SafeInt &s1, const SafeInt &s2) throw(Overflow, DivByZero)
{
    if (s2.value == 0) throw DivByZero();
    if ((s2.value > 0 && s2.value < 1) && (s1.value > INT_MAX * s2.value || s1.value < INT_MIN * s2.value)) throw Overflow();
    if ((s2.value < 0 && s2.value > -1) && (s1.value < INT_MAX * s2.value || s1.value > INT_MIN * s2.value)) throw Overflow();
    return SafeInt(static_cast<double>(s1.value) / s2.value);
}

ostream &operator<<(ostream & os, const SafeInt &s)
{
    os << s.value;
    return os;
}
