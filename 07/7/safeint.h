#ifndef SAFEINT_H_INCLUDED
#define SAFEINT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Overflow{};
    class DivByZero{};

    class SafeInt
    {
        friend SafeInt operator+(const SafeInt &s1, const SafeInt &s2) throw(Overflow);
        friend SafeInt operator-(const SafeInt &s1, const SafeInt &s2) throw(Overflow);
        friend SafeInt operator*(const SafeInt &s1, const SafeInt &s2) throw(Overflow);
        friend SafeInt operator/(const SafeInt &s1, const SafeInt &s2) throw(Overflow, DivByZero);
        friend ostream &operator<<(ostream &os, const SafeInt &s);
    private:
        int value;
    public:
        SafeInt(int v = 0);
        SafeInt(const SafeInt &s);
    };




#endif // SAFEINT_H_INCLUDED
