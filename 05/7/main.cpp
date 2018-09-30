#include <iostream>

using namespace std;
int prime_factor_num(int n, int p);

int main()
{
    int n, p;
    cout << "Please input the value of integers 'n' and 'p'" << endl;
    cin >> n >> p;
    cout << n << "! includes " << prime_factor_num(n, p) << " prime factor " << p;
    return 0;
}

int prime_factor_num(int n, int p)
{
    int k = 1;
    int num = 0;
    for (int i = 2; i <= n; i++) k *= i;
    while (k % p == 0)
    {
        k = k / p;
        num += 1;
    }
    return num;
}
