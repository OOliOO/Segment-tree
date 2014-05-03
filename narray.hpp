#ifndef NARRAY_HPP
#define NARRAY_HPP
#include <iostream>
#include "nvector.hpp"

///////////////////////
//N-dimensional array//
///////////////////////

template<typename T> class NArray{
public:
    NArray(NVector size):dim(size.dim),size(size){
        int memory_needed=1;
        for(int i=0; i<size.dim; i++)
            memory_needed*=size[i];
        memory=new T[memory_needed];

        linear_size=memory_needed;
    }

    const int dim;
    T& operator [] (NVector v_idx){
        if(v_idx.dim!=dim)
            std::cerr<<"Index vector has too few/many dimensions"<<std::endl;
        return memory[get_idx(v_idx)];
    }

    void initialize(T value){
        for(int i=0; i<linear_size; i++)
            memory[i]=value;
    }
private:
    T* memory;
    NVector size;
    int linear_size;

    int get_idx(NVector v_idx){
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
};

#endif
