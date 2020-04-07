#ifndef IRULAN_VECTOR3_H
#define IRULAN_VECTOR3_H

namespace iru {
    template<typename T>
    class Vector3 {
    public:
        T x, y, z;

        Vector3() = default;
        Vector3(T x, T y, T z): x(x), y(y), z(z){};

        Vector3<T>& operator=(const Vector3<T> &vec);
        Vector3<T> operator*(const Vector3<T> &vec) const;
        Vector3<T>& operator*=(const Vector3<T> &vec);
        Vector3<T> operator+(const Vector3<T> &vec) const;
        Vector3<T>& operator+=(const Vector3<T> &vec);
        Vector3<T> operator-(const Vector3<T> &vec) const;
        Vector3<T>& operator-=(const Vector3<T> &vec);

        Vector3<T> normalize() const;
        Vector3<T> cross(const Vector3<T> &vec) const;
    };


    using Vector3i = Vector3<int>;
    using Vector3f = Vector3<float>;
}

#include "Vector3.tpp"

#endif //IRULAN_VECTOR3_H
