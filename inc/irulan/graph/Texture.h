#ifndef IRULAN_TEXTURE_H
#define IRULAN_TEXTURE_H

#include "irulan/system/opengl/Pointer.h"
#include "irulan/math/Vector2.h"
#include <iostream>

namespace iru {
    class Texture {
        friend class Renderer;
    public:
        Texture();

        void loadPng(const std::string& path);
    private:
        Vector2i size;
        ogl::Pointer<ogl::Texture> ptr;
    };
}

#endif //IRULAN_TEXTURE_H
