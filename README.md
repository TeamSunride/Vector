# Vector

A vector class designed to be used with arduino, but could be used anywhere I suppose.
    

### Usage
```cpp
Vector<double, 3> v1 {1.2, 0.141, 3.14}; // Constructor using std::initializer_list<T>
Vector<int, 3> v2 {0, 1, 2};

// Cross product
Vector<double, 3> vCross = v1.cross(v2);
```

---
### Vector operations 

There are a number of vector operations:
- `norm()` take the norm of the caller vector (magnitude)
- `dot(Vector<T> v)` dot product of caller vector and v (not limited to 3 dimensions).
- `normalise()` normalise the caller vector
- `normalised()` get the normalised version of the caller vector
- `cross(Vector<T> v)` get the cross product of the caller vector and v (only 3D);
- `directionCosines()` get the direction cosines of the caller vector: `l`, `m`, `n`.

---

TODO: 
- Transforms by rotation matrices
- Standard reference frame transforms (for accelerometers in different reference frames).