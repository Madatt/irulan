#include <algorithm>
#include <cmath>
#include "irulan/math/Matrix4.h"


namespace iru {
    Matrix4::Matrix4() :
            data{1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 1} {
    }

    Matrix4::Matrix4(const std::initializer_list<float>& list) {
        for (int i = 0; i < 16; i++)
            data[i] = *(list.begin() + i);
    }

    Matrix4::Matrix4(const Matrix4& mat) {
        std::copy(mat.data, mat.data + 16, data);
    }

    Matrix4& Matrix4::operator=(const Matrix4& mat) {
        for (int i = 0; i < 16; i++)
            data[i] = mat.data[i];
        return *this;
    }

    Matrix4 Matrix4::operator+(const Matrix4& mat) const {
        Matrix4 nw;
        for (int i = 0; i < 16; i++)
            nw.data[i] = data[i] + mat.data[i];
        return nw;
    }

    Matrix4 Matrix4::operator-(const Matrix4& mat) const {
        Matrix4 nw;
        for (int i = 0; i < 16; i++)
            nw.data[i] = data[i] - mat.data[i];
        return nw;
    }

    float& Matrix4::operator[](int n) {
        return data[n];
    }

    const float& Matrix4::operator[](int n) const {
        return data[n];
    }

    Matrix4 Matrix4::operator*(const Matrix4& mat) const {
        Matrix4 nw;
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                nw.data[x * 4 + y] = 0.0;
                for (int k = 0; k < 4; k++) {
                    nw.data[x * 4 + y] += data[y + k * 4] * mat.data[k + x * 4];
                }
            }
        }

        return nw;
    }

    Matrix4& Matrix4::operator+=(const Matrix4& mat) {
        return (*this = *this + mat);
    }

    Matrix4& Matrix4::operator-=(const Matrix4& mat) {
        return (*this = *this - mat);
    }

    Matrix4& Matrix4::operator*=(const Matrix4& mat) {
        return (*this = *this * mat);
    }

    Vector3f Matrix4::apply(const Vector3f& vec) const {
        return iru::Vector3f();
    }

    Matrix4 Matrix4::getIdentity() {
        return Matrix4();
    }

    Matrix4 Matrix4::createPerspective(float fov, float asp, float n, float f) {
        float dtr = M_PI / 180.0;
        float y = 1.f / tan(dtr * fov / 2.f);
        float x = y / asp;
        float nf = n - f;

        return Matrix4(
                {
                        x, 0, 0, 0,
                        0, y, 0, 0,
                        0, 0, (f + n) / nf, -1,
                        0, 0, 2 * f * n / nf, 0,
                });
    }

    Matrix4 Matrix4::createOrtho(int w, int h, float n, float f) {
        float ww = w - 1.f;
        float hh = h - 1.f;

        return Matrix4({
                               2.f / ww, 0, 0, 0,
                               0, -2 / hh, 0, 0,
                               0, 0, 2.f / (n - f), 0,
                               -1, 1, (n + f) / (n - f), 1,
                       });
    }

    Matrix4 Matrix4::createLookAt(const Vector3f& ori, const Vector3f& tar, const Vector3f& up) {
        Vector3f forw = ori - tar;
        forw = forw.normalize();

        Vector3f left = up.cross(forw);
        left = left.normalize();

        Vector3f up2 = forw.cross(left);

        Matrix4 mat = getIdentity();

        mat[0] = left.x;
        mat[4] = left.y;
        mat[8] = left.z;
        mat[1] = up2.x;
        mat[5] = up2.y;
        mat[9] = up2.z;
        mat[2] = forw.x;
        mat[6] = forw.y;
        mat[10] = forw.z;

        mat[12] = -left.x * ori.x - left.y * ori.y - left.z * ori.z;
        mat[13] = -up2.x * ori.x - up2.y * ori.y - up2.z * ori.z;
        mat[14] = -forw.x * ori.x - forw.y * ori.y - forw.z * ori.z;

        return mat;
    }

    Matrix4 Matrix4::createRotation(const Vector3f& axis, float angle) {
        Vector3 ax = axis.normalize();
        float x = ax.x;
        float y = ax.y;
        float z = ax.z;

        float a = M_PI / 180.f * angle;
        float c = std::cos(a);
        float s = std::sin(a);
        float cc = (1.f - c);

        Matrix4 mat = getIdentity();

        mat[0] = c + x * x * cc;
        mat[1] = x * y * cc + z * s;
        mat[2] = z * x * cc - y * s;
        mat[3] = 0.f;

        mat[4] = x * y * cc - z * s;
        mat[5] = c + y * y * cc;
        mat[6] = z * y * cc + x * s;
        mat[7] = 0.f;

        mat[8] = x * z * cc + y * s;
        mat[9] = y * z * cc - x * s;
        mat[10] = c + z * z * cc;
        mat[11] = 0.f;

        mat[12] = 0.f;
        mat[13] = 0.f;
        mat[14] = 0.f;
        mat[15] = 1.f;

        return mat;
    }

    Matrix4 Matrix4::createTranslation(const Vector3f& vec) {
        Matrix4 mat;

        mat[12] = vec.x;
        mat[13] = vec.y;
        mat[14] = vec.z;

        return mat;
    }

    Matrix4 Matrix4::createScale(const Vector3f& vec) {
        return Matrix4({
                               vec.x, 0, 0, 0,
                               0, vec.y, 0, 0,
                               0, 0, vec.z, 0,
                               0, 0, 0, 1,
                       });
    }
}