//
// Created by yaros on 09.05.2021.
//

#ifndef LINFORM_ARRAYSEQUENCE_CPP
#define LINFORM_ARRAYSEQUENCE_CPP

#include "Sequence.h"
#include "DynamicArray.h"
#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray <T> items;
public:

    ArraySequence()
    {
        items = DynamicArray<T>();
    }

    explicit ArraySequence(size_t count)
    {
        items = DynamicArray<T>(count);
    }

    explicit ArraySequence(int count) : ArraySequence((size_t) count) {}

    ArraySequence(T *items, size_t count)
    {
        this->items = DynamicArray<T>(items, count);
    }

    template<size_t N>
    explicit ArraySequence(T (&items)[N]) : ArraySequence(items, N) {}

    ArraySequence(initializer_list<T> items) : ArraySequence()
    {
        for (T item : items)
            this->Append(item);
    }

    ArraySequence(ArraySequence<T> const &list)
    {
        items = DynamicArray<T>(list.items);
    }

    explicit ArraySequence(Sequence <T> &list) : ArraySequence((*dynamic_cast<ArraySequence<T> *>(&list))){}

    explicit ArraySequence(Sequence <T> *list) : ArraySequence(*list) {}

    explicit ArraySequence(const ArraySequence<T> *list) : ArraySequence(*list) {}

    explicit ArraySequence(const unique_ptr<Sequence <T>>&list) :ArraySequence(list.get()) {}

    explicit ArraySequence(const unique_ptr<ArraySequence<T>> &list) : ArraySequence(*list) {}


    T &GetI(size_t index) {
        return items.GetI(index);
    }

    T &operator[](size_t index) { return GetI(index); }

    ArraySequence<T> *Concat(Sequence<T> &list) {
        ArraySequence<T> *res = new ArraySequence<T>();
        for (size_t i = 0; i < items.GetLength(); ++i) {
            res->Append(items[i]);
        }
        for (size_t i = 0; i < list.GetLength(); ++i) {
            res->Append(list[i]);
        }
        return res;
    }


    size_t GetLength() {
        return items.GetLength();
    }

    void Append(T item) {
        items.Resize(items.GetLength() + 1);
        items.Set(items.GetLength() - 1, item);
    }

    void InsertAt(T item, size_t index) {
        items.Resize(items.GetLength() + 1);

        for (size_t i = items.GetLength() - 1; i > index; --i) {
            items.Set(i, items[i - 1]);
        }
        if (items.GetLength() - 2 != index)
            items.Set(index, item);
        else
            items.Set(items.GetLength() - 1, item);
    }

    void Prepend(T item) {
        items.Resize(items.GetLength() + 1);
        for (size_t i = items.GetLength() - 1; i > 0; --i) {
            items.Set(i, items.GetI(i - 1));
        }
        items.Set(0, item);
    }
};

#endif //LINFORM_ARRAYSEQUENCE_CPP
