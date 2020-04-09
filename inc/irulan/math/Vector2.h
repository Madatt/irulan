#ifndef IRULAN_VECTOR2_H
#define IRULAN_VECTOR2_H


namespace iru {
    template<typename T>
    class Vector2 {
    public:
        T x{}, y{};

        Vector2() = default;
        Vector2(T x, T y): x(x), y(y){};

        Vector2& operator=(const Vector2& vec);
        Vector2 operator*(const Vector2& vec) const;
        Vector2 operator*(const T& val) const;
        Vector2 operator/(const T& val) const;
        Vector2 operator+(const Vector2& vec) const;
        Vector2 operator-(const Vector2& vec) const;
        Vector2& operator*=(const Vector2& vec);
        Vector2& operator*=(const T& val);
        Vector2& operator/=(const T& val);
        Vector2& operator+=(const Vector2& vec);
        Vector2& operator-=(const Vector2& vec);
    };

    using Vector2i = Vector2<int>;
    using Vector2f = Vector2<float>;
}

#include "Vector2.tpp"

#endif //IRULAN_VECTOR2_H
