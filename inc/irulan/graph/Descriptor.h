#ifndef IRULAN_DESCRIPTOR_H
#define IRULAN_DESCRIPTOR_H

#include "irulan/system/opengl/Pointer.h"

namespace iru {
    class Descriptor {
        friend class Renderer;
    public:
        Descriptor();
        void setAttrib(unsigned int vi , unsigned int i, unsigned int count, unsigned int offset);

    private:
        ogl::Pointer<ogl::VertexArray> ptr;
        unsigned int offset = 0;
    };
}

#endif //IRULAN_DESCRIPTOR_H
