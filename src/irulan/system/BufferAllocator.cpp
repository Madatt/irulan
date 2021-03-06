#include <irulan/system/Buffer.h>
#include <iostream>
#include "irulan/system/BufferAllocator.h"
#include "glad/glad.h"
#include "irulan/system/Log.h"

namespace iru {
    BufferAllocator::BufferAllocator(unsigned int pool)
            : pool(pool) {
    }

    BufferAllocator::~BufferAllocator() {

    }

    BufferBlock* BufferAllocator::alloc(unsigned int size) {
        for (auto curr = head; curr != nullptr; curr = curr->next) {
            if (curr->size >= size and curr->free) {
                unsigned int ns = curr->size - size;
                curr->free = false;
                curr->size = size;

                defaultLog() << "[BufferAllocator] Allocated new buffer: " << size << ", vb = " << curr->id << "\n";

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

                return curr;
            }
        }

        newBlock(size > pool ? size : pool);
        return alloc(size);
    }

    void BufferAllocator::free(BufferBlock* buffer) {
        if (buffer->ba == this) {
            defaultLog() << "[BufferAllocator] Freed block: " << buffer->size << ", vb = " << buffer->id << "\n";
            buffer->free = true;
        }
    }


    Buffer* BufferAllocator::newBuffer(unsigned int size) {
        auto block = alloc(size);
        return new Buffer(block);
    }

    void BufferAllocator::newBlock(unsigned int size) {
        auto nw = new BufferBlock;
        nw->free = true;
        nw->size = size;
        glCreateBuffers(1, &(nw->id));
        glNamedBufferStorage(nw->id, size, nullptr, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        nw->ptr = glMapNamedBufferRange(nw->id, 0, size,
                                        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

        defaultLog() << "[BufferAllocator] Allocated new block: " << size << ", vb = " << nw->id << "\n";

        if (head == nullptr)
            head = nw;
        else
            head->last()->next = nw;
    }
}