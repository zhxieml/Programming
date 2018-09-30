#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Matrix
    {
        friend Matrix operator+(const Matrix &m1, const Matrix &m2);
        friend Matrix operator*(const Matrix &m1, const Matrix &m2);
        friend ostream &operator<<(ostream &os, const Matrix &obj);
        friend istream &operator>>(istream &is, const Matrix &obj);
    private:
        int row;
        int column;
        double **m;
    public:
        Matrix(int r = 1, int c = 1);
        Matrix(const Matrix &matrix);
        Matrix &operator=(const Matrix &matrix);
        void transpose();
        ~Matrix();

    };


#endif // MATRIX_H_INCLUDED
