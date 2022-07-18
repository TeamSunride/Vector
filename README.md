# Vector

A vector class designed to be used with arduino, but could be used anywhere I suppose.
    

### Usage
```cpp
Vector<double, 3> v1 {1.2, 0.141, 3.14}; // Constructor using std::initializer_list<T>
Vector<int, 3> v2 {0, 1, 2};

Vector<double, 3> v1 {2.4, 0, 0};
Vector<double, 3> v2 {0, 2.4, 0};
Vector<double, 3> v3 = v1.cross(v2);

Vector<double, 3> v4 = v3.normalized();

Vector<double, 3> v5 = v4 * 2;

Vector<double, 3> v6 = v4 / 2;

Vector<double, 3> v7 = {1, 2, 3};
Vector<double, 3> v8 = {4, 5, 6};
double dot = v7.dot(v8);

double norm = v7.norm();
double mag = v7.magnitude(); // identical to norm

Vector<double, 3> v9 = v7; // copy assignment
v9 *= 2;

Vector<double, 3> v10 = std::move(v9); // move assignment

v10 /= 2;

// Vector operations
Vector<double, 3> v1v2Cross = v1.cross(v2);
Vector<double, 3> v1UnitVector = v1.normalized();

// Vector casting
Vector<int, 3> vInt = {1, 2, 3};
Vector<double, 3> vDouble = (Vector<double, 3>) vInt;


```

---
### Vector operations 

There are a number of vector operations:
- `norm()` take the norm of the caller vector (magnitude)
- `dot(Vector<T, s> v)` dot product of caller vector and v (not limited to 3 dimensions).
- `normalise()` normalise the caller vector
- `normalised()` get the normalised version of the caller vector
- `cross(Vector<T, s> v)` get the cross product of the caller vector and v (only 3D);
- `directionCosines()` get the direction cosines of the caller vector: `l`, `m`, `n`.

---

TODO: 
- Transforms by rotation matrices
- Standard reference frame transforms (for accelerometers in different reference frames).