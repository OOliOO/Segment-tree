#include <iostream>
#include "narray.hpp"
#include "sparse_narray.hpp"
#include "dense_narray.hpp"
#include "segment_tree.hpp"
using namespace std;

int sum(int a, int b){
    return a+b;
}

int main(){
    //SparseNArray<int> lol(NVector(3,10,10,10),0);
    ///this is an example for 3d integer sum segment tree
    SegmentTree<int> spuu(NVector(3,10,10,10),sum,0,true);
    for(int i=0; i<10; i++)
        for(int e=0; e<10; e++)
            for(int a=0; a<10; a++)
                spuu.update(NVector(3,i,e,a),1);
    cout<<spuu.get(NVector(3,1,1,1),NVector(3,9,9,9))<<endl;
    return 0;
}
