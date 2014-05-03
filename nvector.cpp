#include "nvector.hpp"

NVector::NVector(int dimensions, ...): dim(dimensions){
    va_list arguments;

    memory=new int[dim];

    va_start(arguments,dimensions);
    for(int i=0; i<dim; i++)
        memory[i]=va_arg(arguments,int);
    va_end(arguments);
}

NVector::NVector(const NVector& v):dim(v.dim){
    memory=new int[dim];

    for(int i=0; i<dim; i++)
        memory[i]=v.memory[i];
}

NVector operator *(int c, NVector v){
    NVector ret=v;
    for(int i=0; i<v.dim; i++)
        ret[i]*=c;
    return ret;
}

NVector operator +(NVector a, NVector b){
    NVector ret=a;
    for(int i=0; i<a.dim; i++)
        ret[i]+=b[i];
    return ret;
}
