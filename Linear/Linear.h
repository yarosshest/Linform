//
// Created by yaros on 09.05.2021.
//

#ifndef LINFORM_LINEAR_CPP
#define LINFORM_LINEAR_CPP
#include "ArraySequence.h"
#include <queue>
#include <sstream>
#include <math.h>
#include <complex>
#include <type_traits>
template<typename T>
class Linear {
private:
    ArraySequence <T> coefficients;

public:
    Linear() : Linear(T()) {}

    explicit Linear(T x) {
        this->coefficients = ArraySequence<T>({x});
    }

    Linear(T *items, size_t count) {
        this->coefficients = ArraySequence<T>(items, count);
    }

    explicit Linear(ArraySequence <T> x) {
        this->coefficients = ArraySequence<T>();
        for (int i = 0; i < x.GetLength(); ++i)
            coefficients.Prepend(x[i]);
    }

    template<size_t N>
    explicit Linear(T (&items)[N]) : Linear(items, N) {}

    Linear(initializer_list <T> items) {
        this->coefficients = ArraySequence<T>();
        for (T item : items)
            coefficients.Append(item);
    }

    size_t GetDimension() { return coefficients.GetLength(); }

    T &GetI(size_t index) {
        return this->coefficients[index];
    }

    T &operator[](size_t index) { return GetI(index); }

    T calc(DynamicArray<T> ar)
    {
        Linear<T> res = Linear<T>(*this);
        T buf = res.coefficients[0];
        for( int i = 0; i<ar.GetLength();i++)
        {
            buf = buf + res.coefficients[i+1]*ar.GetI(i);
        }
        return buf;
    }

    friend ostream &operator<<(ostream &out, Linear<T> x) {
        if constexpr  (is_constructible_v<T, complex<float>>)
        {
            complex<float> zero(0, 0);
            if (x.coefficients[0] != zero)
                out << x.coefficients[0] << ' ';
            for (size_t i = 1; i < x.coefficients.GetLength() ; i++)
                if (x.coefficients[i] != zero)
                    out<< "+ " << x.coefficients[i] << "*"<<"x"<< i <<' ';
            out << endl;
        }
        else
        {
            bool first = true;
            if (x.coefficients[0] != 0)
            {
                first = false;
                out << x.coefficients[0] << ' ';
            }
            for (size_t i = 1; i < x.coefficients.GetLength() ; i++)
            {
                if ((x.coefficients[i] > 0 )&&(!first))
                {
                    out << "+"<< x.coefficients[i] << "*"<<"x"<< i <<' ';
                }
                else if ((x.coefficients[i] < 0)||(first)&&(x.coefficients[i] > 0 ))
                {
                    out << x.coefficients[i] << "*"<<"x"<< i <<' ';
                    first = false;
                }

            }
            out << endl;
        }
        return out;
    }

    friend istream& operator>>(istream &in, Linear &lin)
    {
        queue<T> data_q;
        bool clear = false;
        string line = "";
        getline(in, line);
        if (line.empty())
            clear = true;

        while (true)
        {
            if (clear)
                getline(in, line);

            if (line.empty())
                break;
            if constexpr  (is_constructible_v<T, complex<float>>)
            {
                istringstream stm(line) ;
                float real, imag ;
                while (stm >> real >> imag)
                    data_q.push(complex<float>(real,imag));
            }
            else if (is_constructible_v<T, float>)
            {
                istringstream iss(line);
                T ch;
                while (iss >> ch)
                    data_q.push(ch);
            }
            clear = true;
        }

        lin.coefficients = ArraySequence<T>();
        int size  = data_q.size();
        for (int i=0; i<size; i++)
        {
            lin.coefficients.Append(data_q.front());
            data_q.pop();
        }
        return in;
    }

    Linear<T> operator*(float a)
    {
        Linear<T> res = Linear<T>(*this);
        for (size_t i = 0; i < res.coefficients.GetLength(); ++i)
        {
            if constexpr  (is_constructible_v<T, complex<float>>)
            {
                complex<float> buff = res.coefficients[i];
                float real = a*buff.real();
                float imag = a*buff.imag();
                res.coefficients[i] = complex<double>(real,imag);;
            }
            else if (is_constructible_v<T, float>)
            {
                res.coefficients[i] = a*res.coefficients[i];
            }
        }
        return res;
    }

    Linear<T> operator+(Linear<T> x) const
    {
        Linear<T> res = Linear<T>(*this);

        for (size_t i = 0; i < x.coefficients.GetLength(); ++i)
        {
            if (res.coefficients.GetLength() <= i)
                res.coefficients.Append(x.coefficients[i]);
            else
            {
                res.coefficients[i] = res.coefficients[i] + x.coefficients[i];
            }
        }
        return res;
    }
    Linear<T> operator-() const
    {
        Linear<T> res = Linear<T>(*this);
        for (size_t i = 0; i < res.coefficients.GetLength(); ++i)
        {
            if constexpr  (is_constructible_v<T, complex<float>>)
            {
                complex<float> buff = res.coefficients[i];
                float real = -buff.real();
                float imag = -buff.imag();
                res.coefficients[i] = complex<double>(real,imag);;
            }
            else if (is_constructible_v<T, float>)
            {
                res.coefficients[i] = -res.coefficients[i];
            }
        }
        return res;
    }

    Linear<T> operator-(Linear<T> x) const
    {
        Linear<T> res = Linear<T>(*this);
        res = res + (-x);
        return res;
    }
};
#endif //LINFORM_LINEAR_CPP
