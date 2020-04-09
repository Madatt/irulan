#ifndef IRULAN_POINTER_H
#define IRULAN_POINTER_H

#include "Traits.h"
#include "irulan/system/Log.h"

namespace iru::ogl {
    template<typename T>
    class Pointer {
        class RefCounter {
            friend class Pointer;
            void inc() { count++; };
            void dec() { count--; };
            int get() { return count; };
            int count = 1;
        };

    public:
        Pointer();
        Pointer(const Pointer<T>& obj);
        ~Pointer();

        Pointer& operator=(const Pointer<T>& obj);

        unsigned int get() const { return id; };

    private:
        RefCounter* rc;
        unsigned int id = 0;
    };
}

#include "Pointer.tpp"

#endif //IRULAN_POINTER_H
