#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
    #include <iostream>
    using namespace std;

    template <class T> class Set;
    template <class T> Set<T> getUnion(const Set<T> &s1, const Set<T> &s2);
    template <class T> Set<T> getIntersection(const Set<T> &s1, const Set<T> &s2);

    template <class T>
    class Set
    {
        friend Set<T> getUnion<T>(const Set<T> &s1, const Set<T> &s2);
        friend Set<T> getIntersection<T>(const Set<T> &s1, const Set<T> &s2);
    private:
        int length;
        T *storage;
        int elementNum;
    public:
        Set(int l = 1);
        Set(const Set &s);
        int searchElement(T e) const;
        void addElement(T e);
        void deleteElement(T e);
        void display() const;
        void setLength(int newl);
        Set &operator=(const Set &s);
        ~Set();
    };

    template <class T>
    Set<T>::Set(int l): length(l)
    {
        storage = new T[length];
        elementNum = 0;
    }

    template <class T>
    Set<T>::Set(const Set<T> &s)
    {
        length = s.length;
        storage = new T[length];
        elementNum = s.elementNum;
        for (int i = 0; i < elementNum; i++) storage[i] = s.storage[i];
    }

    template <class T>
    Set<T>::~Set()
    {
        delete [] storage;
    }

    template <class T>
    Set<T> &Set<T>::operator=(const Set<T> &s)
    {
        if (this == &s) return *this;
        delete [ ] storage;
        length = s.length;
        storage = new T[length];
        elementNum = s.elementNum;
        for (int i = 0; i < elementNum; i++) storage[i] = s.storage[i];
        return *this;
    }

    template <class T>
    int Set<T>::searchElement(T e) const
    {
        int index = -1;
        for (int i = 0; i < elementNum; i++)
        {
            if (storage[i] == e)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    template <class T>
    void Set<T>::addElement(T e)
    {
        if (elementNum == length)
        {
            cout << "Max size is reached!" << endl;
            return;
        }

        int index = searchElement(e);
        if (index != -1)
        {
            cout << "The element already exists!" << endl;
            return;
        }
        storage[elementNum] = e;
        elementNum++;
    }

    template <class T>
    void Set<T>::deleteElement(T e)
    {
        int index = searchElement(e);
        if (elementNum == 0 || index == -1)
        {
            cout << "There is no element to delete!" << endl;
            return;
        }

        for (int i = index; i < elementNum; i++) storage[i] = storage[i + 1];
        elementNum--;
    }

    template <class T>
    void Set<T>::display() const
    {
        if (elementNum == 0)
        {
            cout << "{}";
            return;
        }

        int i;
        cout << "{";
        for (i = 0; i < elementNum - 1; i++) cout << storage[i] << ",";
        cout << storage[i] << "}";
    }

    template <class T>
    void Set<T>::setLength(int newl)
    {
        if (newl < elementNum)
        {
            cout << "Invalid length for the original set!" << endl;
            return;
        }

        length = newl;
        T *tmp;
        tmp = new T[newl];
        for (int i = 0; i < elementNum; i++) tmp[i] = storage[i];
        delete [] storage;
        storage = tmp;
    }

    template <class T>
    Set<T> getUnion(const Set<T> &s1, const Set<T> &s2)
    {
        int length = s1.elementNum + s2.elementNum;
        Set<T> s(length);
        for (int i = 0; i < s1.elementNum; i++)
        {
            if (s.searchElement(s1.storage[i]) == -1) s.addElement(s1.storage[i]);
        }

        for (int i = 0; i < s2.elementNum; i++)
        {
            if (s.searchElement(s2.storage[i]) == -1) s.addElement(s2.storage[i]);
        }

        return s;
    }

    template <class T>
    Set<T> getIntersection(const Set<T> &s1, const Set<T> &s2)
    {
        int length = s1.elementNum < s2.elementNum ? s1.elementNum : s2.elementNum;
        Set<T> s(length);
        if (s1.elementNum > s2.elementNum)
        {
            for (int i = 0; i < s2.elementNum; i++)
            {
                if (s1.searchElement(s2.storage[i]) != -1) s.addElement(s2.storage[i]);
            }
        }

        else
        {
            for (int i = 0; i < s1.elementNum; i++)
            {
                if (s2.searchElement(s1.storage[i]) != -1) s.addElement(s1.storage[i]);
            }
        }

        return s;
    }
#endif // SET_H_INCLUDED
