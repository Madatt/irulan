#ifndef IRULAN_MATRIX4_H
#define IRULAN_MATRIX4_H

#include "Vector3.h"
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
        Vector3f operator*(const Vector3f& vec) const;
        Matrix4& operator+=(const Matrix4& mat);
        Matrix4& operator-=(const Matrix4& mat);
        Matrix4& operator*=(const Matrix4& mat);

        static Matrix4 getIdentity();
        static Matrix4 createPerspective(float fov, float asp, float n, float f);
        static Matrix4 createOrtho(int w, int h, float t_n, float f);
        static Matrix4 createLookAt(const Vector3f& ori, const Vector3f& tar, const Vector3f& up);
        static Matrix4 createRotation(const Vector3f& axis, float angle);
        static Matrix4 createTranslation(const Vector3f& vec);
        static Matrix4 createScale(const Vector3f& vec);

    };
}

#endif //IRULAN_MATRIX4_H
