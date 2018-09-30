#include <iostream>
#include "Joseph.h"
using namespace std;

Joseph::Joseph(int n, int i): num(n), interval(i)
{
    cycle = new int[num];
    for (int j = 0; j < num; j++) cycle[j] = 1; // Set the flags;
}

void Joseph::simulate()
{
    int count_num = 0, index = 0, searcher = 1;
    while (count_num < num)
    {
        if (cycle[index] == 1 && searcher == interval)
        {
            cout << index + 1 << " ";
            count_num++;
            cycle[index] = 0;
            index++;
            index = index % num;
            searcher = 1;   // Initialize;
            continue;
        }
        index++;
        index = index % num;
        searcher++;
    }
}

Joseph::~Joseph()
{
    delete [] cycle;
}
