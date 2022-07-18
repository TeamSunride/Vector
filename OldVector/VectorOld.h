//
// Created by robosam2003 2022
//


#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H



#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

template<typename T>
class Vector {
public:
    Vector();
    // constructors
    explicit Vector(int size);
    Vector(std::initializer_list<T> lst);

    int size() const;

    // Copy
    /**
     * @brief Copy constructor for Vector, note that Vector is a resource handler, so a copy constructor is needed such that copying is a memberwise copy
     * @param a
     */
    Vector(const Vector& a);            // copy constructor

    /**
     * @brief Copy assignment constructor for Vector. Usage: Vector<int> v1 {1, 2, 3}; Vector<int> v2 = v1;
     * @param a
     * @return
     */
    Vector& operator=(const Vector& a); // copy assignment


    // Move
    /**
     * @brief Move constructor for Vector.
     * @param a - an rvalue reference to a Vector
     */
    Vector(Vector&& a) noexcept ;            // move constructor

    /**
     * @brief Move assignment constructor for Vector. Usage: Vector<int> v1 {1, 2, 3}; Vector<int> v2 = std::move(v1);
     * @param a
     * @return
     */
    Vector& operator=(Vector&& a) noexcept ; // move assignment

    // operators
    /**
     * @brief operator []
     * @param i
     * @return the i-th element of the vector
     */
    T& operator[](int i) const; /// const specifier means "Do not modify in this scope" - i.e. we do not modify member variables in this scope

    /**
     * @brief operator / : divide all elements by a scalar
     * @param scalar
     * @return the vector divided by the scalar
     */
    Vector<T> operator/(double scalar) const;

    /**
     * @brief operator /= : divide equals all elements by a scalar
     * @param scalar
     * @return reference to the caller vector
     */
    Vector<T> & operator/=(double scalar);

    /**
     * @brief operator * : multiply all elements by a scalar
     * @param scalar
     * @return the vector multiplied by the scalar
     */
    Vector<T> operator*(double scalar) const;

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
    Vector<T> operator+(Vector<T> v) const;

    /**
     * @brief operator - : subtract v from caller vector
     * @param v
     * @return the result of the sum
     */
    Vector<T>operator-(Vector<T> v);

    // TODO: iterators? begin functions for range-for?

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

    // TODO: Rotation matricies etc

    ~Vector() { delete[] elem; } // destructor - implicit definition
protected:
    T* elem;
    int sz;
};


#include "VectorOld.tpp"

#endif //VECTOR_LIBRARY_H
