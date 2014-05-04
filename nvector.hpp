#ifndef NVECTOR_HPP
#define NVECTOR_HPP

#include <stdarg.h>

////////////////////////
//N-dimensional vector//
////////////////////////

class NVector{
public:
    NVector(int dimensions, ...);
    NVector(const NVector& v);
    const int dim;

    int& operator [] (int idx){return memory[idx];}
    void operator = (NVector b);

private:
    int* memory;
};

NVector operator *(int c, NVector v);
NVector operator +(NVector a, NVector b);
#endif
