#include "Vector3.h"
#include <cmath>

namespace iru {
    template<typename T>
    inline Vector3<T> &Vector3<T>::operator=(const Vector3<T> &vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        return *this;
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator*(const Vector3<T> &vec) const {
        Vector3 res;
        res.x = this->x * vec.x;
        res.y = this->y * vec.y;
        res.z = this->z * vec.z;

        return res;
    }

    template<typename T>
    inline Vector3<T> &Vector3<T>::operator*=(const Vector3<T> &vec) {
        return (*this = *this * vec);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator+(const Vector3<T> &vec) const {
        Vector3 res;
        res.x = this->x + vec.x;
        res.y = this->y + vec.y;
        res.z = this->z + vec.z;

        return res;
    }

    template<typename T>
    inline Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &vec) {
        return (*this = *this + vec);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator-(const Vector3<T> &vec) const {
        Vector3 res;
        res.x = this->x - vec.x;
        res.y = this->y - vec.y;
        res.z = this->z - vec.z;

        return res;
    }

    template<typename T>
    inline Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &vec) {
        return (*this = *this - vec);
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::normalize() const {
        Vector3<T> res;

        res.x = x;
        res.y = y;
        res.z = z;

        float l = std::sqrt(x * x + y * y + z * z);
        if (l == 0)
            return res;

        res.x = x / l;
        res.y = y / l;
        res.z = z / l;

        return res;
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::cross(const Vector3<T> &vec) const {
        Vector3 res;

        res.x = this->y * vec.z - this->z * vec.y;
        res.y = this->z * vec.x - this->x * vec.z;
        res.z = this->x * vec.y - this->y * vec.x;

        return res;
    }
}