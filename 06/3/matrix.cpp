#include "matrix.h"
#include <iostream>
#include "assert.h"
using namespace std;

Matrix::Matrix(int r, int c): row(r), column(c)
{
    m = new double *[row];
    for (int i = 0; i < row; i++) m[i] = new double[column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) m[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix &matrix)
{
    row = matrix.row;
    column = matrix.column;
    m = new double *[row];
    for (int i = 0; i < row; i++) m[i] = new double[column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) m[i][j] = matrix.m[i][j];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < row; i++) delete [] m[i];
    delete [] m;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix tmp = m1;
    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.column; j++) tmp.m[i][j] += m2.m[i][j];
    }
    return tmp;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    assert(m1.column == m2.row);
    Matrix tmp(m1.row, m2.column);
    for (int i = 0; i < tmp.row; i++)
    {
        for (int j = 0; j < tmp.column; j++)
        {
            for (int p = 0; p < m1.column; p++) tmp.m[i][j] += m1.m[i][p] * m2.m[p][j];
        }
    }
    return tmp;
}

ostream &operator<<(ostream &os, const Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++) os << obj.m[i][j] << " ";
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, const Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.column; j++)
        {
            cout << "(" << i << "," << j << "):";
            is >> obj.m[i][j];
        }
    }
    return is;
}

Matrix &Matrix::operator=(const Matrix &matrix)
{
    if (this == &matrix) return *this;
    for (int i = 0; i < row; i++) delete [] m[i];
    delete [] m;
    row = matrix.row;
    column = matrix.column;
    m = new double *[row];
    for (int i = 0; i < row; i++) m[i] = new double[column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) m[i][j] = matrix.m[i][j];
    }
    return *this;
}

void Matrix::transpose()
{
    double **newm;
    newm = new double *[column];
    for (int i = 0; i < column; i++) newm[i] = new double[row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) newm[j][i] = m[i][j];
    }

    for (int i = 0; i < row; i++) delete [] m[i];
    delete [] m;
    m = newm;

    int tmp = row;
    row = column;
    column = tmp;
}
