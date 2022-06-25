#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H

#include <iostream>

template<typename T>
class Vector {
public:
    // constructors
    explicit Vector(int s);
    Vector(std::initializer_list<T> lst);
    [[nodiscard]] int size() const;
    // TODO: Copy constructors

    // operators
    T& operator+=(Vector<T> v);
    T& operator[](int i);
    //T operator/(Vector<T> v, double scalar);



    ~Vector() { delete[] elem; } // destructor
private:
    T* elem;
    int sz;
};


#endif //VECTOR_LIBRARY_H
