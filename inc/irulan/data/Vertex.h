#ifndef IRULAN_VERTEX_H
#define IRULAN_VERTEX_H

#include "irulan/math/Vector3.h"
#include "irulan/math/Vector2.h"

namespace iru {
    class Vertex {
    public:
        Vector3f pos;
        Vector2f texPos;
        Vector3f norm;

        Vertex(const Vector3f& pos, const Vector2f& texPos = Vector2f(), const Vector3f& norm = Vector3f())
                : pos(pos), texPos(texPos), norm(norm) {};
    };
}

#endif //IRULAN_VERTEX_H
