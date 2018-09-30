#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class cat
    {
    private:
        double weight;
        static double total_weight;
        static double total_number;
    public:
        cat(double w)
        {
            weight = w;
            total_weight += w;
            total_number++;
            cout << "Con " << total_number << " weight " << weight << endl;
        }

        cat(const cat &c)
        {
            weight = c.weight;
            total_weight += weight;
            total_number++;
            cout << "ConCopy " << total_number << " weight " << weight << endl;
        }

        static void total_disp()
        {
            cout << total_number << " cats total weight ";
            cout << total_weight << " pounds" << endl;
        }

        void display() const
        {
            cout << weight;
        }

        ~cat()
        {
            cout << "De " << total_number << endl;
            total_number--;
        }
    };

    double cat::total_weight = 0;
    double cat::total_number = 0;


#endif // CAT_H_INCLUDED
