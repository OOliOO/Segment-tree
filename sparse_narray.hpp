#ifndef SPARSE_NARRAY_HPP
#define SPARSE_NARRAY_HPP
#include "narray.hpp"
#include <unordered_map>

template<typename T> class SparseNArray: public NArray<T>{
    using NArray<T>::size;
    using NArray<T>::dim;
    using NArray<T>::get_idx;
public:
    SparseNArray(NVector array_size, T init_value);
    T& operator[](NVector v_idx);
private:
    T init_val;
    std::unordered_map<int, T> sparse_data;
};

template<typename T> SparseNArray<T>::SparseNArray(NVector array_size, T init_value):
    NArray<T>(array_size, init_value),
    init_val(init_value){}

template<typename T> T& SparseNArray<T>::operator[](NVector v_idx){
    if(v_idx.dim!=dim)
        std::cerr<<"Index vector has too few/many dimensions"<<std::endl;

    int real_idx=get_idx(v_idx);
    if(sparse_data.count(real_idx)==0)
        sparse_data[real_idx]=init_val;
    return sparse_data[real_idx];
}

#endif
