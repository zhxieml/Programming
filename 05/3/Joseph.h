#ifndef JOSEPH_H_INCLUDED
#define JOSEPH_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Joseph
    {
    private:
        int num;
        int interval;
        int *cycle;
    public:
        Joseph(int n, int i);
        void simulate();
        ~Joseph();
    };


#endif // JOSEPH_H_INCLUDED
