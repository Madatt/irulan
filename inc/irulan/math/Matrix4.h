#ifndef IRULAN_MATRIX4_H
#define IRULAN_MATRIX4_H

#include <initializer_list>

namespace iru {
    class Matrix4 {
    public:
        float data[4*4];

        Matrix4();
        Matrix4(const std::initializer_list<float>& list);
        Matrix4(const Matrix4& mat);

        float& operator[](int n);
        const float& operator[](int n) const;
        Matrix4& operator=(const Matrix4& mat);
        Matrix4 operator+(const Matrix4& mat) const;
        Matrix4 operator-(const Matrix4& mat) const;
        Matrix4 operator*(const Matrix4& mat) const;

        Matrix4& operator+=(const Matrix4& mat);
        Matrix4& operator-=(const Matrix4& mat);
        Matrix4& operator*=(const Matrix4& mat);

    };
}

#endif //IRULAN_MATRIX4_H
