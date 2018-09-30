#include "reader.h"
#include "assert.h"
#include <iostream>
#include <cstring>
using namespace std;

Reader::Reader(int n, char *nm, char *d): no(n), name(nm), dept(d)
{
    borrow_num = 0;
    assert(reader_num < 20);
}

int Reader::getID() const
{
    return no;
}

int Reader::getBorrowNum() const
{
    return borrow_num;
}

int *Reader::getRecord() const
{
    return record;
}

Reader::~Reader()
{
    delete [] record;
}
