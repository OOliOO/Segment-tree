#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP
#include "narray.hpp"
//////////////////////////////
//N-dimensional segment tree//
//////////////////////////////

template<typename T> class SegmentTree{
public:
    SegmentTree(NVector size, T (*f)(T,T), T zero_element);

    void update(NVector pos, T val);
    T get(NVector left_bound, NVector right_bound);

    const int dim;
private:
    T (*operation)(T,T);    //must be a valid operation for segment tree...
    NVector SIZE;
    NArray<T> data;
    T zero;

    void update_dim(NVector pos, int level);
    T get_dim(NVector left, NVector right, int level);

    NVector real_size(NVector initial_size);
};

template<typename T> SegmentTree<T>::SegmentTree(NVector size, T (*f)(T,T), T zero_element):dim(size.dim), operation(f), SIZE(real_size(size)),data(2*SIZE), zero(zero_element){
    data.initialize(zero);
}

template<typename T> NVector SegmentTree<T>::real_size(NVector initial_size){
    NVector ret=initial_size;
    for(int i=0; i<initial_size.dim; i++){
        for(int p=1;;p*=2)
            if(ret[i]<=p){
                ret[i]=p;
                break;
            }
    }
    return ret;
}

template<typename T> void SegmentTree<T>::update(NVector position, T val){
    NVector pos=position+SIZE;
    data[pos]=val;
    update_dim(pos,0);
}

template<typename T> void SegmentTree<T>::update_dim(NVector pos, int level){
    if(level<dim-1)
        update_dim(pos,level+1);

    pos[level]/=2;

    while(pos[level]>0){
        NVector l=pos,r=pos;

        l[level]=2*l[level];
        r[level]=2*r[level]+1;
        data[pos]=operation(data[l],data[r]);

        if(level<dim-1)
            update_dim(pos,level+1);
        pos[level]/=2;
    }
}


template<typename T> T SegmentTree<T>::get(NVector left_bound, NVector right_bound){
    NVector left=left_bound+SIZE;
    NVector right=right_bound+SIZE;

    return get_dim(left,right,0);
}

template<typename T> T SegmentTree<T>::get_dim(NVector left, NVector right, int level){
    T ret=zero;
    if(level==dim-1){
        while(left[level]<=right[level]){
            if(left[level]%2==1){
                ret=operation(ret,data[left]);
                left[level]++;
            }

            if(right[level]%2==0){
                ret=operation(ret,data[right]);
                right[level]--;
            }

            right[level]/=2;
            left[level]/=2;
            if(right[level]==left[level])
                return operation(ret,data[left]);
        }
        return ret;
    }

    while(left[level]<=right[level]){
        if(left[level]%2==1){
            NVector new_right=right;
            new_right[level]=left[level];
            ret=operation(ret,get_dim(left,new_right,level+1));
            left[level]++;
        }

        if(right[level]%2==0){
            NVector new_left=left;
            new_left[level]=right[level];
            ret=operation(ret,get_dim(new_left,right,level+1));
            right[level]--;
        }

        right[level]/=2;
        left[level]/=2;
        if(right[level]==left[level])
            return operation(ret,get_dim(left,right,level+1));
    }
    return ret;
}

#endif
