#ifndef IRULAN_TEXTURE2D_H
#define IRULAN_TEXTURE2D_H

#include "Texture.h"
#include "irulan/math/Vector2.h"
#include <iostream>

namespace iru {
    class Texture2D : public Texture {
        friend class Renderer;
    public:
        Texture2D();

        void createDepth(const Vector2i& size);
        void loadPng(const std::string& path);
    private:
        Vector2i size;
    };
}

#endif //IRULAN_TEXTURE2D_H
