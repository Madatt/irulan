#ifndef IRULAN_BUFFER_H
#define IRULAN_BUFFER_H

#include "BufferAllocator.h"

namespace iru {
    class Buffer {
        friend class BufferAllocator;

    public:
        ~Buffer();

        void setData(unsigned int size, unsigned int off, void* data);
        unsigned int getOffset() const { return block->offset; };
        unsigned int getSize() const { return block->size; };
    private:
        BufferBlock* block;

        Buffer() = delete;
        Buffer(BufferBlock* t_bb);

    };
}

#endif //IRULAN_BUFFER_H
