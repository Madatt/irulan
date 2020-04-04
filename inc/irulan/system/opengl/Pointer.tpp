#include "Pointer.h"

namespace iru::ogl {
    template<typename T>
    Pointer<T>::Pointer() {
        rc = new RefCounter();
        id = T::alloc();
    }

    template<typename T>
    Pointer<T>::Pointer(const Pointer<T>& obj) {
        obj.rc->inc();
        rc = obj.rc;
        id = obj.id;
    }

    template<typename T>
    Pointer<T>::~Pointer() {
        rc->dec();
        if (rc->get() <= 0) {
            delete rc;
            T::free(id);
        }
    }

    template<typename T>
    Pointer<T>& Pointer<T>::operator=(const Pointer<T>& obj) {
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