#include "irulan/graph/Descriptor.h"
#include "irulan/system/Buffer.h"
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

    void Descriptor::attachBuffer(Buffer* buffer, unsigned int i, unsigned int start , unsigned int stride) {
        glVertexArrayVertexBuffer(ptr.get(), i, buffer->block->id, buffer->block->offset + start, stride);
    }

    void Descriptor::attachIBuffer(Buffer* buffer) {
        glVertexArrayElementBuffer(ptr.get(), buffer->block->id);
        offset = buffer->block->offset;
    }
}