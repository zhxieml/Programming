#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Vector
    {
        friend Vector operator+(const Vector &v1, const Vector &v2);
        friend ostream &operator<<(ostream &os, const Vector &obj);
        friend istream &operator>>(istream &is, const Vector &obj);
        friend bool operator==(const Vector &v1, const Vector &v2);
        friend bool operator!=(const Vector &v1, const Vector &v2);
    private:
        static int create_num;
        static int living_num;
        int dim;
        double *vec;
    public:
        Vector(int d = 1);
        Vector(const Vector &v);
        ~Vector();
        double &operator[](int i);
        Vector &operator=(const Vector &v);
        Vector &operator++();
        Vector operator++(int);
        Vector &operator--();
        Vector operator--(int);
        operator double () const;
        void displayDim() const;
        static int createN();
        static int livingN();
    };


#endif // VECTOR_H_INCLUDED
