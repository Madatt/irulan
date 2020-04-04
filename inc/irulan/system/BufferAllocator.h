#ifndef IRULAN_BUFFERALLOCATOR_H
#define IRULAN_BUFFERALLOCATOR_H

namespace iru {
    const unsigned int POOL_SIZE = sizeof(float) * 3 * 10000;

    class BufferAllocator;
    class Buffer;

    struct BufferBlock {
        unsigned int id = 0;
        unsigned int size = 0;
        unsigned int offset = 0;
        unsigned int free = 0;
        void* ptr;

        BufferAllocator* ba = nullptr;
        BufferBlock* next = nullptr;

        BufferBlock* last() {
            if(next == nullptr)
                return this;
            else return next->last();
        }
    };

    class BufferAllocator {
    public:
        BufferAllocator();
        ~BufferAllocator();

        Buffer* alloc(unsigned int size);
        void free(Buffer* buffer);

    private:
        BufferBlock* head = nullptr;
        void newBlock(unsigned int size);
    };
}

#endif //IRULAN_BUFFERALLOCATOR_H
