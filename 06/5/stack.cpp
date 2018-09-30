#include "stack.h"
#include <iostream>
#include "assert.h"
using namespace std;

Stack::Stack(int s): scale(s), num(0)
{
    assert(scale > 0);
    stack_array = new int[scale];
    for (int i = 0; i < scale; i++) stack_array[i] = 0; // Initialize the array.For the sake of convenience, the element are set all 0;
}

Stack::Stack(const Stack &s)
{
    num = s.num;
    stack_array = new int[s.scale];
    for (int i = 0; i < s.scale; i++) stack_array[i] = s.stack_array[i];
    top = &stack_array[num - 1];
}

void Stack::Push(int n)
{
     if (num == 0)
    {
        top = stack_array;  // Set the top;
        *top = n;
        num++;
        cout << "Push "<< n <<" successfully!" << endl;
        return;
    }
    if (scale == num)
    {
        cout << "The stack is full." << endl;
        return;
    }
    cout << "Push "<< n <<" successfully!" << endl;

    top++;
    *top = n;
    num++;
}

void Stack::Pop()
{
    if (num == 0)
    {
        cout << "The stack is empty." << endl;
        return;
    }
    cout << *top;
    top--;
    num--;
}

Stack::~Stack()
{
    delete [] stack_array;
}
