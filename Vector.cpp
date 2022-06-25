#include "Vector.h"

#include <iostream>

// constructors
template<typename T>
Vector<T>::Vector(int s) {
    if (s<0) s = 0; /// minimum Vector length is 0
    elem = new double[s];
    sz = s;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst) { // usage: Vector<int> {1, 2 ,3} // creates a vector of size 3
    elem = new T[lst.size()];
    sz = static_cast<int>(lst.size());
    std::copy(lst.begin(), lst.end(), elem); // copy from lst to elem
}



template<typename T>
T &Vector<T>::operator[](int i) {
    if (i<0) i = 0; /// minimum index is 0
    if (i>=sz) i = sz-1; /// maximum index is sz-1
    return elem[i];
}

template<typename T>
T &Vector<T>::operator+=(Vector<T> v) {
    // assert the sizes are the same
    static_assert(sz == v.sz, "Cannot add together Vectors of different size (operator+=)");
    for (int i=0;i<sz;i++) {
        elem[i] += v[i];
    }
}

template<typename T>
int Vector<T>::size() const {
    return sz;
}


