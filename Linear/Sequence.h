//
// Created by yaros on 09.05.2021.
//

#ifndef LINFORM_SEQUENCE_CPP
#define LINFORM_SEQUENCE_CPP
#include <iostream>
#include <memory>
using namespace std;

template<class T>
class Sequence{
public:
    Sequence() {}

    //Decomposition
    T &GetFirst() { return GetI(0); }

    T &GetLast() { return GetI(this->GetLength() - 1); }

    void Set(size_t index, T value) {
        GetI(index) = value;
    }

    virtual T &GetI(size_t index) = 0;

    virtual size_t GetLength() = 0;


    T &operator[](size_t index) { return GetI(index); }

    //Operations
    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, size_t index) = 0;

    virtual Sequence<T> *Concat(Sequence<T> &list) = 0;

    virtual Sequence<T> *Concat(const unique_ptr<Sequence<T>> &list) {
        return Concat(*list);
    }

    virtual ~Sequence() {};
};
#endif //LINFORM_SEQUENCE_CPP
