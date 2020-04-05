#ifndef IRULAN_DESCRIPTOR_H
#define IRULAN_DESCRIPTOR_H

#include "irulan/system/Buffer.h"
#include "irulan/system/opengl/Pointer.h"

namespace iru {
    class Descriptor {
        friend class Renderer;
    public:
        Descriptor();

        void attachBuffer(Buffer* buffer, unsigned int i, unsigned int start , unsigned int stride);
        void attachIBuffer(Buffer* buffer);
        void setAttribute(unsigned int i, unsigned int count, unsigned int offset);
        void setAttributeBuffer(unsigned int i, unsigned int vi);
    private:
        ogl::Pointer<ogl::VertexArray> ptr;
        unsigned int offset = 0;
    };
}

#endif //IRULAN_DESCRIPTOR_H
