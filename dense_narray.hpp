#ifndef DENSE_NARRAY_HPP
#define DENSE_NARRAY_HPP

template<typename T> class DenseNArray:public NArray<T>{
    using NArray<T>::size;
    using NArray<T>::dim;
    using NArray<T>::get_idx;
public:
    DenseNArray(NVector size, T init_value);
    T& operator[](NVector v_idx);
private:
    T* memory;
    int linear_size;

    void initialize(T value);
};

template<typename T> DenseNArray<T>::DenseNArray(NVector size, T init_value):
    NArray<T>(size, init_value){

    int memory_needed=1;
    for(int i=0; i<size.dim; i++)
        memory_needed*=size[i];
    memory=new T[memory_needed];

    linear_size=memory_needed;

    initialize(init_value);
}

template<typename T> T& DenseNArray<T>::operator[](NVector v_idx){
    if(v_idx.dim!=dim)
        std::cerr<<"Index vector has too few/many dimensions"<<std::endl;
    return memory[get_idx(v_idx)];
}

template<typename T> void DenseNArray<T>::initialize(T value){
    for(int i=0; i<linear_size; i++)
        memory[i]=value;
}


#endif
