#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
    #include <iostream>
    using namespace std;
    template <class T> class LinkList;
    template <class T> class Queue;
    template <class T> ostream &operator<<(ostream &, const LinkList<T> &);

    // The definition of class Node;
    template <class T>
    class Node
    {
        friend class LinkList<T>;
        friend class Queue<T>;
        friend ostream &operator<<<T>(ostream &, const LinkList<T> &);
    private:
            T data;
            Node<T> *next;
    public:
        Node(const T &d, Node<T> *n = NULL): data(d), next(n){};
        Node(): next(NULL){};
        ~Node(){};
    };

    // The definition of class LinkList;
    template <class T>
    class LinkList
    {
        friend ostream &operator<<<T>(ostream &, const LinkList<T> &);
    protected:
        Node<T> *head;
        void makeEmpty();
    public:
        LinkList();
        ~LinkList();
        void create(const T &flag);
    };

    template <class T>
    void LinkList<T>::makeEmpty()
    {
        Node<T> *p = head->next, *q;
        head->next=NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }

    template <class T>
    LinkList<T>::LinkList()
    {
        head  = new Node<T>;
    }

    template <class T>
    LinkList<T>::~LinkList()
    {
        makeEmpty();
        delete head;
    }

    template <class T>
    void LinkList<T>::create(const T &flag)
    {
        T tmp;
        Node<T>*p, *q = head;

        cout << "Please input the data, with " << flag << " as the flag of the end" << endl;
        while (true)
        {

            cin >> tmp;
            if (tmp == flag) break;
            p = new Node<T>(tmp);
            q->next = p;
            q = p;
         }
         q->next = NULL;
    }

    template <class T>
    ostream &operator<<(ostream &os, const LinkList<T> &obj)
    {
        Node<T> *q = obj.head->next;
        os << endl;
        while (q != NULL)
        {
            os << q->data;
            q = q->next;
        }
        return os;
    }

    // The definition of class Queue;
    template <class T>
    class Queue: public LinkList<T>
    {
    private:
        int length;
    public:
        Queue(){length = 0;}
        void queueIn(const T &data);
        bool queueOut(T &data);
        int getLength();
    };

    template <class T>
    void Queue<T>::queueIn(const T &data)
    {
        Node<T> *p = new Node<T>(data);
        p->next = this->head->next;
        this->head->next = p;
        length++;
    }

    template <class T>
    bool Queue<T>::queueOut(T &data)
    {
        Node<T> *p = this->head->next;
        if (p == NULL) return false;
        this->head->next = p->next;
        data = p->data;
        delete p;
        return true;
    }

    template <class T>
    int Queue<T>::getLength()
    {
        return length;
    }

#endif // QUEUE_H_INCLUDED
