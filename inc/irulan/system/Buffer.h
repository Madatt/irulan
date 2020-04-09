#ifndef IRULAN_BUFFER_H
#define IRULAN_BUFFER_H

#include "BufferAllocator.h"
#include <vector>
#include <memory.h>

namespace iru {
    class Buffer {
        friend class BufferAllocator;
        friend class Descriptor;

    public:
        ~Buffer();

        void setData(unsigned int size, unsigned int off, void* data);

        template<typename T>
        void setData(unsigned int off, const std::vector<T>& data) {
            memcpy((void *) ((intptr_t) (block->ptr) + off + block->offset), data.data(), data.size() * sizeof(T));
        }

        unsigned int getOffset() const { return block->offset; };
        unsigned int getSize() const { return block->size; };
    private:
        BufferBlock* block;
        Buffer() = delete;
        Buffer(BufferBlock* block);

    };
}

#endif //IRULAN_BUFFER_H
