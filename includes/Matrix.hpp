#pragma once 


#include <vector>
#include <iostream>

template <typename K>
class Matrix{
    private:
        std::vector<std::vector<K>> _data;
    public:
        
        Matrix(std::initializer_list<std::initializer_list<K>> values) {
            for (const auto& row : values)
                _data.emplace_back(row);
        }
        void print(){
            for (size_t i = 0; i < _data.size(); i++) {
                for (size_t j = 0; j < _data[i].size(); j++) {
                    if (_data[i][j] == (int)_data[i][j])
                        std::cout << "[" << _data[i][j] << ".0]";
                    else
                        std::cout << "[" << _data[i][j] << "]";
                }
                std::cout << std::endl;
            }
        }
        void add(Matrix<K> &others){
            for (size_t i = 0 ; i < _data.size() ;i++)
                for (size_t j = 0 ; j < _data[i].size() ;j++)
                    _data[i][j] = _data[i][j] + others[i][j];
        }
        void sub(Matrix<K> &others){
            for (size_t i = 0 ; i < _data.size() ;i++)
                for (size_t j = 0 ; j < _data[i].size() ;j++)
                    _data[i][j] = _data[i][j] - others[i][j];
        }
        void scl(K num){
            for (size_t i = 0 ; i < _data.size() ;i++)
                for (size_t j = 0 ; j < _data[i].size() ;j++)
                    _data[i][j] = _data[i][j] * num;
        }
        std::vector<K> &operator[](size_t i) {return _data[i];}
}; 
