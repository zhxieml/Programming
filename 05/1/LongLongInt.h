#ifndef LONGLONGINT_H_INCLUDED
#define LONGLONGINT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class LongLongInt
    {
    private:
        int length;
        int *storage;
    public:
        LongLongInt(const char *num = "0");
        LongLongInt(const LongLongInt &lli);
        void add(LongLongInt a, LongLongInt b);
        void display();
        ~LongLongInt();
    };


#endif // LONGLONGINT_H_INCLUDED
