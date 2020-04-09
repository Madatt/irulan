#include "Pointer.h"

namespace iru::ogl {
    template<typename T>
    Pointer<T>::Pointer() {
        rc = new RefCounter();
        id = T::alloc();
        defaultLog << "[ogl::Pointer] Allocated new OpenGl object" << "\n";
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
            defaultLog << "[ogl::Pointer] Freed OpenGl object" << "\n";
        }
    }

    template<typename T>
    Pointer<T>& Pointer<T>::operator=(const Pointer<T>& obj) {
        rc->dec();
        if (rc->get() <= 0) {
            delete rc;
            T::free(id);
            defaultLog << "[ogl::Pointer] Freed OpenGl object" << "\n";

        }

        obj.rc->inc();
        rc = obj.rc;
        id = obj.id;

        return *this;
    }
}