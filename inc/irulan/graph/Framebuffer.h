#ifndef IRULAN_FRAMEBUFFER_H
#define IRULAN_FRAMEBUFFER_H

#include "irulan/system/opengl/Pointer.h"
#include "irulan/graph/Texture.h"
#include <initializer_list>

namespace iru {
    class Framebuffer {
        friend class Renderer;
    public:
        void bindColorTexture(Texture* tex, int n, int level = 0);
        void bindDepthTexture(Texture* tex, int level = 0);
        void attach(std::initializer_list<unsigned int> arr);

    protected:
        ogl::Pointer<ogl::Framebuffer> ptr;
    };
}

#endif //IRULAN_FRAMEBUFFER_H
