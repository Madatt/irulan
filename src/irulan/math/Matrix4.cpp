#include <algorithm>
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
        std::copy(mat.data, mat.data + 16, data);
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
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                nw.data[i * 4 + j] = 0.0;
                for (int k = 0; k < 4; k++) {
                    nw.data[i * 4 + j] += data[j + k * 4] * data[k + j * 4];
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
}