#include "Vector2.h"

namespace iru {
    template<typename T>
    Vector2<T>& Vector2<T>::operator=(const Vector2& vec) {
        x = vec.x;
        y = vec.y;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*(const Vector2& vec) const {
        Vector2 nw;
        nw.x = x * vec.x;
        nw.y = y * vec.y;
        return nw;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*(const T& val) const {
        Vector2 nw;
        nw.x = x * val;
        nw.y = y * val;
        return nw;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/(const T& val) const {
        Vector2 nw;
        nw.x = x / val;
        nw.y = y / val;
        return nw;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2& vec) const {
        Vector2 nw;
        nw.x = x + vec.x;
        nw.y = y + vec.y;
        return nw;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2& vec) const {
        Vector2 nw;
        nw.x = x - vec.x;
        nw.y = y - vec.y;
        return nw;
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator*=(const Vector2& vec) {
        return (*this = *this * vec);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator*=(const T& val) {
        return (*this = *this * val);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator/=(const T& val) {
        return (*this = *this / val);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2& vec) {
        return (*this = *this + vec);
    }

    template<typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2& vec) {
        return (*this = *this - vec);
    }
}