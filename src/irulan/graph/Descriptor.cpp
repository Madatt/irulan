#include "irulan/graph/Descriptor.h"
#include "glad/glad.h"

namespace iru {
    Descriptor::Descriptor()
            : ptr() {
    }

    void Descriptor::setAttrib(unsigned int vi, unsigned int i, unsigned int count, unsigned int off) {
        glBindVertexArray(ptr.get());
        glEnableVertexArrayAttrib(ptr.get(), i);
        glVertexArrayAttribFormat(ptr.get(), i, count, GL_FLOAT, GL_FALSE, off);
        glVertexArrayAttribBinding(ptr.get(), i, vi);
    }
}