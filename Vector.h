#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H

#include <iostream>
#include <cmath>

template<typename T>
class Vector {
public:
    // constructors
    explicit Vector(int s);
    Vector(std::initializer_list<T> lst);

    int size() const;
    // TODO: Copy constructors

    // operators
    /**
     * @brief operator []
     * @param i
     * @return the i-th element of the vector
     */
    T& operator[](int i);

    /**
     * @brief operator / : divide all elements by a scalar
     * @param scalar
     * @return the vector divided by the scalar
     */
    Vector<T> operator/(double scalar);

    /**
     * @brief operator /= : divide equals all elements by a scalar
     * @param scalar
     * @return reference to the caller vector
     */
    Vector<T>& operator/=(double scalar);

    /**
     * @brief operator * : multiply all elements by a scalar
     * @param scalar
     * @return the vector multiplied by the scalar
     */
    Vector<T> operator*(double scalar);

    /**
     * @brief operator *= : multiply equals all elements by a scalar
     * @param scalar
     * @return reference to the caller vector
     */
    Vector<T>& operator*=(double scalar);

    /**
     * @brief operator += : add equals two vectors of the same size together
     * @param v
     * @return reference to the caller vector
     */
    Vector<T>& operator+=(Vector<T> v);
    /**
     * @brief operator -= : subtract v from caller vector
     * @param v
     * @return reference to the caller vector
     */
    Vector<T>& operator-=(Vector<T> v);

    /**
     * @brief operator + : add two vectors of the same size together
     * @param v
     * @return the result of the sum
     */
    Vector<T> operator+(Vector<T> v);

    /**
     * @brief operator - : subtract v from caller vector
     * @param v
     * @return the result of the sum
     */
    Vector<T>operator-(Vector<T> v);
    // TODO: iterators?

    // Vector operations
    /**
     * @brief calculate the norm of a vector
     * @return the norm of the caller vector
     */
    double norm() const;

    /**
     * @brief calculate the dot product of the caller vector and v
     * @param v
     * @return the dot (scalar) product of the caller vector and v
     */
    double dot(Vector<T> v) const;

    /**
     * @brief normalise the caller vector
     * @return reference to the normalised caller vector
     */
    Vector<T>& normalize();

    /**
     * @brief normalise the caller vector
     * @return the normalised caller vector.
     */
    Vector<T> normalized() const;

    /**
     * @brief calculate the cross product of the caller vector and v
     * @param v
     * @return the cross product of the caller vector and v
     */
    Vector<T> cross(Vector<T> v) const;

    /**
     * @brief calculate the direction cosines triad of the caller vector
     * @param v
     * @return the direction cosines triad of the caller vector
     */
    Vector<T> directionCosines() const;


    ~Vector() { delete[] elem; } // destructor
private:
    T* elem;
    int sz;
};

// constructors
template<typename T>
Vector<T>::Vector(int s) {
    if (s<0) s = 0; /// minimum Vector length is 0
    elem = new T[s];
    sz = s;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst) { // usage: Vector<int> {1, 2 ,3} // creates a vector of size 3
    elem = new T[lst.size()];
    sz = static_cast<int>(lst.size());
    std::copy(lst.begin(), lst.end(), elem); // copy from lst to elem
}

// operators
template<typename T>
T &Vector<T>::operator[](int i) {
//    if (i<0) return 0;
//    if (i>=sz) return 0;
    return elem[i];
}

template<typename T>
int Vector<T>::size() const {
    return sz;
}

template<typename T>
Vector<T> Vector<T>::operator*(double scalar) {
    Vector<T> v(sz);
    for (int i=0; i<sz; i++) {
        v[i] = elem[i] * scalar;
    }
    return v;

}

template<typename T>
Vector<T> Vector<T>::operator/(double scalar) {
    Vector<T> v(sz);
    for (int i=0; i<sz; i++) {
        v[i] = elem[i] / scalar;
    }
    return v;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(double scalar) {
    for (int i=0; i<sz; i++) {
        elem[i] /= scalar;
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator*=(double scalar) {
    for (int i=0; i<sz; i++) {
        elem[i] *= scalar;
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator+=(Vector<T> v) {
    for (int i=0; i<sz; i++) {
        elem[i] += v[i];
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator-=(Vector<T> v) {
    for (int i=0; i<sz; i++) {
        elem[i] -= v[i];
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(Vector<T> v) {
    Vector<T> rv(sz);
    for (int i=0; i<sz; i++) {
        rv[i] = elem[i] + v[i];
    }
    return rv;
}

template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> v) {
    Vector<T> rv(sz);
    for (int i=0; i<sz; i++) {
        rv[i] = elem[i] - v[i];
    }
    return rv;
}


// Vector operations
template<typename T>
double Vector<T>::norm() const {
    double sum = 0;
    for (int i=0; i<sz; i++) {
        sum += elem[i] * elem[i];
    }
    return sqrt(sum);
}

template<typename T>
double Vector<T>::dot(Vector<T> v) const {
    double sum = 0;
    for (int i=0; i<sz; i++) {
        sum += elem[i] * v[i];
    }
    return sum;
}

template<typename T>
Vector<T> &Vector<T>::normalize() {
    double norm = this->norm();
    this /= norm;
    return *this;
}

template<typename T>
Vector<T> Vector<T>::normalized() const {
    double norm = this->norm();
    Vector<T> v(sz);
    v /= norm;
    return v;
}

template<typename T>
Vector<T> Vector<T>::cross(Vector<T> v) const { /// only works for 3D vectors
    Vector<T> rv = {0, 0, 0};
    rv[0] = elem[1] * v[2] - elem[2] * v[1]; // i
    rv[1] = elem[2] * v[0] - elem[0] * v[2]; // j
    rv[2] = elem[0] * v[1] - elem[1] * v[0]; // k
    return rv;
}

template<typename T>
Vector<T> Vector<T>::directionCosines() const {
    /// Note that: l^2 + m^2 + n^2 = 1
    Vector<T> rv = {0, 0, 0};
    double norm = this->norm();
    rv[0] = elem[0] / norm; /// l = cos(alpha) = x/r
    rv[1] = elem[1] / norm; /// m = cos(beta) = y/r
    rv[2] = elem[2] / norm; /// n = cos(gamma) = z/r
    return rv;
}


#endif //VECTOR_LIBRARY_H
