#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s1(3);
    s1.Push(4);
    s1.Push(3);
    s1.Push(5);
    s1.Push(2);
    s1.Push(6);
    s1.Pop();
    cout << endl;
    s1.Pop();
    cout << endl;
    s1.Pop();
    cout << endl;
    s1.Pop();
    return 0;
}
