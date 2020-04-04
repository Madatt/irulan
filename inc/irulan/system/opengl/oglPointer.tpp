#include "oglPointer.h"

namespace iru {
    template<typename T>
    oglPointer<T>::oglPointer() {
        rc = new RefCounter();
        id = T::alloc();
    }

    template<typename T>
    oglPointer<T>::oglPointer(const oglPointer<T>& obj) {
        obj.rc->inc();
        rc = obj.rc;
        id = obj.id;
    }

    template<typename T>
    oglPointer<T>::~oglPointer() {
        rc->dec();
        if (rc->get() <= 0) {
            delete rc;
            T::free(id);
        }
    }

    template<typename T>
    oglPointer<T>& oglPointer<T>::operator=(const oglPointer<T>& obj) {
        rc->dec();
        if (rc->get() <= 0) {
            delete rc;
            T::free(id);
        }

        obj.rc->inc();
        rc = obj.rc;
        id = obj.id;

        return *this;
    }
}