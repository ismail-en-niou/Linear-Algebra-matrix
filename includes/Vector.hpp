#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

template <typename K>
class Vector{
    private:
        std::vector<K> _data;
    public:
        Vector(std::initializer_list<K> _values): _data(_values){}
        explicit Vector(size_t n) : _data(n, K()) {}

        K       &operator[](size_t i)       { return _data[i]; }
        const K &operator[](size_t i) const { return _data[i]; }
        
        K getValue(size_t i){return _data[i];}
        
        size_t getSize() const {return _data.size();}

        void add(Vector<K> &others){
            for (size_t i = 0 ; i < _data.size() ;i++)
                _data[i] = _data[i] + others[i];
        }

        void sub(Vector<K> &_others){
            for (size_t i = 0 ; i < _data.size() ;i++)
                _data[i] = _data[i] - _others[i];
        }
        void scl(K num)
        {
            for (size_t i = 0 ; i < _data.size() ;i++)
                _data[i] = _data[i] * num;
        }

        void print() const {
            for (size_t i = 0; i < _data.size(); i++) {
                if (_data[i] == (int)_data[i])
                    std::cout << "[" << _data[i] << ".0]" << std::endl;
                else
                    std::cout << "[" << _data[i] << "]" << std::endl;
            }
        }
};

template <typename K>
Vector<K> linear_combination(const std::vector<Vector<K>> &vectors, const std::vector<K> &coefficients) 
{
    if (vectors.size() != coefficients.size() || vectors.empty())
        throw std::invalid_argument("Vectors and coefficients must have the same size.");
    size_t dim = vectors[0].getSize();
    Vector<K> result(dim);
    for (size_t k = 0; k < vectors.size(); k++)
        for (size_t i = 0; i < dim; i++)
            result[i] = std::fma(coefficients[k], vectors[k][i], result[i]);

    return result;
}