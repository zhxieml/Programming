#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Stack
    {
    private:
        int *stack_array;
        int scale;
        int *top;
        int num;
    public:
        Stack(int s = 100);
        Stack(const Stack &s);
        void Push(int n);
        void Pop();
        ~Stack();
    };

#endif // STACK_H_INCLUDED
