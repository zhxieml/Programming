#include "vector.h"
#include <iostream>
#include "stdlib.h"
#include <cmath>
using namespace std;

int Vector::create_num = 0;
int Vector::living_num = 0;

Vector::Vector(int d): dim(d)
{
    create_num++;
    living_num++;
    vec = new double[dim];
    for (int i = 0; i < dim; i++) vec[i] = 0;
}

Vector::~Vector()
{
    living_num--;
    delete [] vec;
}

Vector::Vector(const Vector &v)
{
    create_num++;
    living_num++;
    dim = v.dim;
    vec = new double[dim];
    for (int i = 0; i < dim; i++) vec[i] = v.vec[i];
}

Vector operator+(const Vector &v1, const Vector &v2)
{
    Vector v = v1;
    for (int i = 0; i < v.dim; i++) v.vec[i] += v2.vec[i];
    return v;
}

double & Vector::operator[](int i)
{
    if (i < 0 || i >= dim)
    {
        cout << "Out of range!";
        exit(-1);
    }
    return vec[i];
}

ostream &operator<<(ostream &os, const Vector &obj)
{
    int i = 0;
    os << "[";
    for (; i < obj.dim - 1; i++) os << obj.vec[i] << ",";
    os << obj.vec[i] << "]";
}

istream &operator>>(istream &is, const Vector &obj)
{
    for (int i = 0; i < obj.dim; i++)
    {
        cout << "dim "<< i + 1 <<":";
        is >> obj.vec[i];
    }
    return is;
}

Vector & Vector::operator=(const Vector &v)
{
    if (this == &v) return *this;
    delete [] vec;
    vec = new double[v.dim];
    for (int i = 0; i < dim; i++) vec[i] = v.vec[i];
    return *this;
}

bool operator==(const Vector &v1, const Vector &v2)
{
    bool flag = true;
    for (int i = 0; i < v1.dim; i++)
    {
        if (v1.vec[i] != v2.vec[i]) return false;
    }
    return true;
}

bool operator!=(const Vector &v1, const Vector &v2)
{
    for (int i = 0; i < v1.dim; i++)
    {
        if (v1.vec[i] != v2.vec[i]) return true;
    }
    return false;
}

Vector & Vector::operator++()
{
    for (int i = 0; i < dim; i++) vec[i]++;
    return *this;
}

Vector Vector::operator++(int)
{
    Vector tmp = *this;
    for (int i = 0; i < dim; i++) vec[i]++;
    return tmp;
}

Vector & Vector::operator--()
{
    for (int i = 0; i < dim; i++) vec[i]--;
    return *this;
}

Vector Vector::operator--(int)
{
    Vector tmp = *this;
    for (int i = 0; i < dim; i++) vec[i]--;
    return tmp;
}

Vector::operator double () const
{
    double length = 0;
    for (int i = 0; i < dim; i++) length += vec[i] * vec[i];
    length = sqrt(length);
    return length;
}


void Vector::displayDim() const
{
    cout << "The dimension of the vector is " << dim << ".";
}

int Vector::createN()
{
    return create_num;
}

int Vector::livingN()
{
    return living_num;
}
