#include <iostream>
#include <ctime>
#include <cstdlib>
#include "queue.h"
using namespace std;

int main()
{
    const int num = 2000;   // Set the simulation time;
    const int cus[10] = { 1,1,1,1,1,1,1,1,1,5 };
    double t1 = 0, t2 = 0;
    srand(unsigned(time(NULL)));

    for (int i = 0; i < num; i++)
    {
        int tmp1 = 0, tmp2 = 0;
        int index_shuffled[10];
        for (int j = 0; j < 10; j++) index_shuffled[j] = -1;
        int countN = 0;
        while (index_shuffled[0] == -1 || index_shuffled[1] == -1 || index_shuffled[2] == -1 || index_shuffled[3] == -1 || index_shuffled[4] == -1 || index_shuffled[5] == -1 || index_shuffled[6] == -1 ||index_shuffled[7] == -1 || index_shuffled[8] == -1 || index_shuffled[9] == -1)
        {
			int ran = rand() % 10;
			if (index_shuffled[ran] == -1)
            {
				index_shuffled[ran] = countN;
				countN += 1;
			}
		}

        // Situation 1;
        Queue<int> q1, q2;
        for (int j = 0; j < 5; j++) q1.queueIn(cus[index_shuffled[j]]);
        for (int j = 5; j < 10; j++) q2.queueIn(cus[index_shuffled[j]]);
        int m, n;
        while (q1.queueOut(m)) tmp1 += m;
        while (q2.queueOut(n)) tmp2 += n;

        t1 += tmp1 > tmp2 ? tmp1 : tmp2;

        // Situation 2;
        int tmp3 = 0, tmp4 = 0;
        Queue<int> q3, q4;
        for (int j = 0; j < 10; j++)
        {
            if (q3.queueOut(m))
            {
                if (q4.queueOut(n))
                {
                    if (n > m)
                    {
                        tmp3 += m;
                        tmp4 += m;
                        q4.queueIn(n - m);
                        q3.queueIn(cus[index_shuffled[j]]);
                    }

                    else if (m > n)
                    {
                        tmp3 += n;
                        tmp4 += n;
                        q3.queueIn(m - n);
                        q4.queueIn(cus[index_shuffled[j]]);
                    }

                    else
                    {
                        tmp3 += m;
                        tmp4 += n;
                        q3.queueIn(cus[index_shuffled[j]]);
                    }
                }

                else
                {
                    tmp3 += m;
                    q4.queueIn(cus[index_shuffled[j]]);
                }

            }

            else q3.queueIn(cus[index_shuffled[j]]);
        }

        t2 += tmp3 > tmp4 ? tmp3 : tmp4;
    }

    t1 /= num;
    t2 /= num;
    cout << t1 << "\t" << t2;

    return 0;
}
