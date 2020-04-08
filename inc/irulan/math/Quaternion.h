#ifndef IRULAN_QUATERNION_H
#define IRULAN_QUATERNION_H
#include "irulan/math/Vector3.h"
#include "irulan/math/Matrix4.h"

namespace iru {
    class Quaternion {
    public:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;

        Quaternion();
        Quaternion(float x, float y, float z, float w);

        Quaternion& operator=(const Quaternion& quat);
        Quaternion operator*(const Quaternion& quat) const;
        Quaternion operator+(const Quaternion& quat) const;
        Quaternion operator-(const Quaternion& quat) const;
        Quaternion& operator*=(const Quaternion& quat);
        Quaternion& operator+=(const Quaternion& quat);
        Quaternion& operator-=(const Quaternion& quat);

        Quaternion normalize() const;
        Quaternion conjugate() const;
        Matrix4 toMatrix() const;

        static Quaternion createRotation(const Vector3f& axis, float angle);
    };
}

#endif //IRULAN_QUATERNION_H
