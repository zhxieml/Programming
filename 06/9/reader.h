#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Reader
    {
    protected:
        int no;
        int *record;
        char *name;
        char *dept;
        int borrow_num;
    public:
        Reader(int n = 0, char *nm = "xxx", char *d = "xxx");
        virtual void borrowBook(int bookNo) = 0;
        virtual void returnBook(int bookNo) = 0;
        int getID() const;
        int getBorrowNum() const;
        int *getRecord() const;
        ~Reader();
    };

    extern Reader *library[20];
    extern int reader_num;

    void help();
    void choice(int n);
    void add_reader();
    void borrowbook();
    void returnbook();
    void showBorrowed();


#endif // READER_H_INCLUDED
