#ifndef SAVINGACCOUNT_H_INCLUDED
#define SAVINGACCOUNT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class SavingAccount
    {
    private:
        static int account_num;
        int account;
        const char *date;
        double money;
        int month;
        static double rate;
    public:
        SavingAccount(const char *d, double m = 0.0);
        static void setRate(double new_rate);
        void showBalance();
    };


#endif // SAVINGACCOUNT_H_INCLUDED
