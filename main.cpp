#include <iostream>
#include "narray.hpp"
#include "segment_tree.hpp"
using namespace std;

int sum(int a, int b){
    return a+b;
}

int main(){
    ///this is an example for 3d integer sum segment tree
    SegmentTree<int> spuu(NVector(3,100,100,100),sum,0);

    spuu.update(NVector(3,1,1,1),1);///set (1,1,1) to be 1
    spuu.update(NVector(3,2,2,2),1);///set (2,2,2) to be 1

    ///now query the sum of elements in rectangle (0,0,0),(1,0,100)
    cout<<spuu.get(NVector(3,0,0,0),NVector(3,1,0,100))<<endl;  ///0
    ///now query the sum of elements in rectangle (1,1,1),(1,1,100)
    cout<<spuu.get(NVector(3,1,1,1),NVector(3,1,1,100))<<endl;  ///1
    ///now query the sum of elements in rectangle (0,0,0),(3,3,3)
    cout<<spuu.get(NVector(3,0,0,0),NVector(3,3,3,3))<<endl;    ///2
    return 0;
}
