#ifndef NARRAY_HPP
#define NARRAY_HPP
#include <iostream>
#include "nvector.hpp"

/////////////////////////////////
//N-dimensional array interface//
/////////////////////////////////

template<typename T> class NArray{
public:
    NArray(NVector size, T zero_element);
    virtual T& operator [] (NVector v_idx)=0;
    const int dim;
protected:
    NVector size;

    int get_idx(NVector v_idx);
};

template<typename T> NArray<T>::NArray(NVector array_size, T zero_element):
    dim(array_size.dim),
    size(array_size){}

template<typename T> int NArray<T>::get_idx(NVector v_idx){
    int k=1;
    int idx=0;
    for(int i=dim-1; i>=0; i--){
        if(v_idx[i]>=size[i])
            std::cerr<<"Index vector out of bounds"<<std::endl;
        idx+=k*v_idx[i];
        k*=size[i];
    }

    return idx;
}

#endif
