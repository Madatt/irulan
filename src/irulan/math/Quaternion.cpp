#include "irulan/math/Quaternion.h"
#include "irulan/math/Matrix4.h"
#include <cmath>

namespace iru {
    Quaternion::Quaternion() {

    }

    Quaternion::Quaternion(float x, float y, float z, float w)
    :x(x), y(y), z(z), w(w){

    }

    Quaternion& Quaternion::operator=(const Quaternion& quat) {
        x = quat.x;
        y = quat.y;
        z = quat.z;
        w = quat.w;
        return *this;
    }

    Quaternion Quaternion::operator*(const Quaternion& quat) const {
        Quaternion nw;
        nw.x = (x * quat.w) + (y * quat.z) + (-z * quat.y) + (w * quat.x);
        nw.y = (-x * quat.z) + (y * quat.w) + (z * quat.x) + (w * quat.y);
        nw.z = (x * quat.y) + (-y * quat.x) + (z * quat.w) + (w * quat.z);
        nw.w = (-x * quat.x) + (-y * quat.y) + (-z * quat.z) + (w * quat.w);
        return nw;
    }

    Quaternion Quaternion::operator+(const Quaternion& quat) const {
        Quaternion nw;
        nw.x = x + quat.x;
        nw.y = y + quat.y;
        nw.z = z + quat.z;
        nw.w = w + quat.w;
        return nw;
    }

    Quaternion Quaternion::operator-(const Quaternion& quat) const {
        Quaternion nw;
        nw.x = x - quat.x;
        nw.y = y - quat.y;
        nw.z = z - quat.z;
        nw.w = w - quat.w;
        return nw;
    }

    Quaternion& Quaternion::operator*=(const Quaternion& quat) {
        return (*this = *this * quat);
    }

    Quaternion& Quaternion::operator+=(const Quaternion& quat) {
        return (*this = *this + quat);
    }

    Quaternion& Quaternion::operator-=(const Quaternion& quat) {
        return (*this = *this - quat);
    }

    Quaternion Quaternion::normalize() const {
        Quaternion quat;

        float n = std::sqrt(x * x + y * y + z * z + w * w);
        if (n == 0.f)
            n = 1.f;

        quat.x = x / n;
        quat.y = y / n;
        quat.z = z / n;
        quat.w = w / n;

        return quat;
    }

    Quaternion Quaternion::conjugate() const {
        Quaternion quat;
        quat.x = -x;
        quat.y = -y;
        quat.z = -z;
        quat.w = w;

        return quat;
    }

    Matrix4 Quaternion::toMatrix() const {
        Matrix4 mat;
        Quaternion cop = this->normalize();

        float xx = cop.x * cop.x;
        float yy = cop.y * cop.y;
        float zz = cop.z * cop.z;

        mat[0] = 1 - 2 * yy - 2 * zz;
        mat[1] = 2 * cop.x * cop.y + 2 * cop.z * cop.w;
        mat[2] = 2 * cop.x * cop.z - 2 * cop.y * cop.w;

        mat[4] = 2 * cop.x * cop.y - 2 * cop.z * cop.w;
        mat[5] = 1 - 2 * xx - 2 * zz;
        mat[6] = 2 * cop.y * cop.z + 2 * cop.x * cop.w;

        mat[8] = 2 * cop.x * cop.z + 2 * cop.y * cop.w;
        mat[9] = 2 * cop.y * cop.z - 2 * cop.x * cop.w;
        mat[10] = 1 - 2 * xx - 2 * yy;

        return mat;
    }

    Quaternion Quaternion::createRotation(const Vector3f& axis, float angle) {
        Vector3f ta = axis.normalize();
        float a = M_PI / 180.f * angle;

        Quaternion quat;

        quat.x = std::sin(a / 2) * ta.x;
        quat.y = std::sin(a / 2) * ta.y;
        quat.z = std::sin(a / 2) * ta.z;
        quat.w = std::cos(a / 2);

        return quat;
    }
}