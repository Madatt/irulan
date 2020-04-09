#ifndef IRULAN_NOISE_H
#define IRULAN_NOISE_H

#include "Vector2.h"

namespace iru::Noise {
    float perlin2f(const Vector2f& pos);
    float perlin2fMulti(const Vector2f& pos, int octaves, float multi);
}


#endif //IRULAN_NOISE_H
