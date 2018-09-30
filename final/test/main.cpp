#include <iostream>
#include <iomanip>
using namespace std;

void swapM(char * &t1, char * &t2)
{
    char *p;
    p = t1;
    t1 = t2;
    t2 = p;
}

int main()
{
    char *a = "bksdajfdsf";
    char *b = "bwewfsdfa";
//    cout << (void *)a << '\t' << (void *)b << endl;
//    a = b;
//    cout << a << '\t' << b << endl;
//    cout << (void *)a << '\t' << (void *)b << endl;
    swapM(a, b);
    cout << a << '\t' << b << endl;
    cout << (void *)a << '\t' << (void *)b << endl;
    return 0;
}
