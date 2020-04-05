#include "irulan/system/Buffer.h"
#include <memory.h>

namespace iru {
    Buffer::~Buffer() {
        block->ba->free(block);
    }

    void Buffer::setData(unsigned int size, unsigned int off, void* data) {
        memcpy((void *) ((intptr_t) (block->ptr) + off + block->offset), data, size);
    }

    Buffer::Buffer(BufferBlock* block)
    :block(block){

    }
}