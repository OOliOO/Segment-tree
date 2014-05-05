Segment-tree
============

N-dimensional Segment tree for fast range queries.

N-dimensional segment tree is a data structure that can handle fast range queries in hyperrectangular areas. 
The queries are of this form: let T be our tree that contains elements of class C, and that has operation O: CxC->C
(which must be associative and commutative!), then get(left, right) returns the operation iterated all over 
the hyperrectangular area.

For examle if our segment tree contains integers and it's 1-dimensional and the operationn is just integer summation then 
get(1,5) would return the sum of all integers in the interwall [1,5]. If our operation was min(int, int) then get would return 
the minimum element in this area.

In two dimensions get((1,1),(2,2)) would do pretty much the same thing, but now in the rectangle (1,1),(2,2),
which contains points (1,1),(1,2),(2,1),(2,2).

Time comlexity assuming that operation is constant time:
update/query = O(log w_1 * log w_2 * ... * log w_n) where w_a is database's width in dimension a. (n is the number of dimensions)

N-dimensional segment tree will need 2^N times the memory compared to the original data.

Interface:
Both queries and updates are done with NVectors which are just n dimensional vectors (the dimension of the vector
should always be the same as the dimension of the segment tree).

SegmentTree(NVector size, T (*f)(T,T), T zero_element, bool sparse=false) constructs a segment tree,
its dimensions will be determined by the NVector size, and f is the segment tree's operation. zero_element should be
a value so that operation(a,zero_element)=a, in case if summation it would be 0, in case of min it would be a large enough integer.

The segment tree will be by default dense. If your segment tree will contain a small amount of updated points compared to all
points then sparse should be true (in a sparse tree only the values that are updated are in memory).

void update(NVector pos, T val) will change the value of the element at point pos to be val.

T get(NVector left_bound, NVector right_bound) will do the query for elements in hyperrectangle defined by left_bound
and right_bound. Please note that left_bound[i] should be less or equal to right_bound[i] for all i<dimension, otherwise 
there are no elements between left_bound and right_bound.
