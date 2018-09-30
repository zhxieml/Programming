#include <iostream>
#include "SavingAccount.h"
using namespace std;

int SavingAccount::account_num = 0;
double SavingAccount::rate = 0.3;

SavingAccount::SavingAccount(const char *d, double m): money(m), date(d)
{
    account_num++;
    month = 0;
    account = account_num;
}

void SavingAccount::showBalance()
{
    month++;
    double money = money * (1 + rate);
    cout << "After " << month << " month, the balance will be " << money << endl;

}

void SavingAccount::setRate(double new_rate)
{
    rate = new_rate;
}
