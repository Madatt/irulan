#include "irulan/math/Noise.h"

namespace iru::Noise {
    inline float fade(float t) {
        return t * t * t * (t * (t * 6 - 15) + 10);
    }

    inline float lerp(float a, float b, float v) {
        return (1.f - v) * a + v * b;
    }

    float noise_grad(int hash, float x, float y) {
        switch (hash & 3) {
            case 0:
                return x + y;
            case 1:
                return -x + y;
            case 2:
                return x - y;
            case 3:
                return -x - y;
        }
    }


    float perlin2f(const Vector2f& pos) {
        static int* pers = nullptr;
        static int rnd[] = {151, 160, 137, 91, 90, 15,
                            131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240,
                            21, 10, 23,
                            190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32,
                            57,
                            177, 33,
                            88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48,
                            27, 166,
                            77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46,
                            245,
                            40, 244,
                            102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169,
                            200,
                            196,
                            135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250,
                            124, 123,
                            5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182,
                            189, 28, 42,
                            223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43,
                            172, 9,
                            129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246,
                            97,
                            228,
                            251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14,
                            239, 107,
                            49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4,
                            150,
                            254,
                            138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156,
                            180
        };

        if (pers == nullptr) {
            pers = new int[512];
            for (int i = 0; i < 256; i++) {
                pers[i] = pers[i + 256] = rnd[i];
            }
        }

        Vector2i pos2((int)pos.x & 255,(int)pos.y & 255);
        Vector2f d(pos.x - pos2.x, pos.y - pos2.y);
        Vector2f uv(fade(d.x), fade(d.y));

        int A = pers[pos2.x] + pos2.y;
        int B = pers[pos2.x + 1] + pos2.y;

        float n0 = noise_grad(A, d.x, d.y);
        float n1 = noise_grad(B, d.x - 1, d.y);
        float n2 = noise_grad(A + 1, d.x, d.y - 1);
        float n3 = noise_grad(B + 1, d.x - 1, d.y - 1);

        return (lerp(lerp(n0, n1, uv.x), lerp(n2, n3, uv.x), uv.y) + 1.f) / 2.f;

    }

    float perlin2fMulti(const Vector2f& pos, int octaves, float multi) {
        float out = 0.0;
        float frequency = 1.0;
        float amplitude = 1.0;
        float mx = 0.0;

        for (int i = 0; i < octaves; i++) {
            out += perlin2f(Vector2f(pos.x * frequency, pos.y * frequency)) * amplitude;
            mx += amplitude;
            amplitude *= multi;
            frequency *= 2.0;
        }

        return out / mx;
    }

}