#ifndef IRULAN_RENDERTARGET_H
#define IRULAN_RENDERTARGET_H

#include "irulan/system/opengl/Pointer.h"

namespace iru {
    class RenderTarget {
        friend class Renderer;
    protected:
        ogl::Pointer<ogl::Framebuffer> ptr;
    };
}

#endif //IRULAN_RENDERTARGET_H
