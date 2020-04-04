#include <irulan/system/Buffer.h>
#include <iostream>
#include "irulan/system/BufferAllocator.h"
#include "glad/glad.h"

namespace iru {
    BufferAllocator::BufferAllocator() {
    }

    BufferAllocator::~BufferAllocator() {

    }

    Buffer* BufferAllocator::alloc(unsigned int size) {
        for (auto curr = head; curr != nullptr; curr = curr->next) {
            if (curr->size >= size and curr->free) {
                unsigned int ns = curr->size - size;
                auto bf = new Buffer(curr);
                curr->free = false;
                curr->size = size;

                std::cout << "Allocated new buffer: " << size << ", vb = " << curr->id << std::endl;

                if (ns > 0) {
                    auto nb = new BufferBlock;
                    nb->id = curr->id;
                    nb->free = true;
                    nb->size = ns;
                    nb->next = curr->next;
                    nb->offset = curr->offset + size;
                    nb->ptr = curr->ptr;
                    curr->next = nb;
                }

                return bf;
            }
        }

        newBlock(size > POOL_SIZE ? size : POOL_SIZE);
        return alloc(size);
    }

    void BufferAllocator::free(Buffer* buffer) {
        if (buffer->block->ba == this)
            buffer->block->free = true;
    }

    void BufferAllocator::newBlock(unsigned int size) {
        auto nw = new BufferBlock;
        nw->free = true;
        nw->size = size;
        glCreateBuffers(1, &(nw->id));
        glNamedBufferStorage(nw->id, size, nullptr, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        nw->ptr = glMapNamedBufferRange(nw->id, 0, size,
                                        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

        std::cout << "Allocated new block: " << size << ", vb = " << nw->id << std::endl;

        if (head == nullptr)
            head = nw;
        else
            head->last()->next = nw;
    }
}