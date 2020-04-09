#ifndef IRULAN_TEXTURE_H
#define IRULAN_TEXTURE_H

#include "irulan/system/opengl/Pointer.h"

namespace iru {
    class Texture {
        friend class Renderer;
        friend class Framebuffer;
    public:
        virtual ~Texture() = 0;

    protected:
        ogl::Pointer<ogl::Texture> ptr;
    };
}
#endif //IRULAN_TEXTURE_H
