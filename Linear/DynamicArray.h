//
// Created by yaros on 27.04.2021.
//

#ifndef LINFORM_DYNAMICARRAY_CPP
#define LINFORM_DYNAMICARRAY_CPP
#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class DynamicArray {
private:
    T *array;
    size_t length;

public:
    DynamicArray() : array(new T[1]()), length(0) {}

    explicit DynamicArray(size_t count) {
        if (count < 0)
            throw out_of_range("count < 0");

        if (count > 0)
            array = new T[count]();
        else
            array = new T[1]();
        length = count;
    }

    DynamicArray(T *items, size_t count) {
        if (count < 0)
            throw out_of_range("count < 0");
        if (items == NULL)
            throw invalid_argument("items is NULL");
        if (count > 0) {
            array = new T[count]();
            memcpy(array, items, count * sizeof(T));
        } else {
            array = new T[1]();
        }
        length = count;
    }

    DynamicArray(DynamicArray<T> const &dynamicArray) {
        length = dynamicArray.length;
        if (length > 0) {
            array = new T[length]();
            memcpy(array, dynamicArray.array, length * sizeof(T));
        } else
            array = new T[1]();
    }

    T &GetI(size_t index) {
        if (index < 0 || index >= length)
            throw out_of_range("index < 0 or index >= length");
        return array[index];
    }

    void Set(size_t index, T value) {
        if (index < 0 || index >= length)
            throw range_error("index < 0 or index >= length");
        GetI(index) = value;
    }

    size_t GetLength() { return length; }

    void Resize(size_t new_length) {
        if (new_length < 0) {
            throw range_error("new_length < 0");
        }
        T *new_array;

        if (new_length > 0) {
            new_array = new T[new_length]();
            size_t len = new_length > length ? length : new_length;
            memcpy(new_array, array, sizeof(T) * len);
        } else new_array = new T[1]();
        delete[] array;
        length = new_length;
        array = new_array;
    }

    T &operator[](size_t index) { return GetI(index); }
};

#endif //LINFORM_DYNAMICARRAY_CPP