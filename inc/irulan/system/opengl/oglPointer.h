#ifndef IRULAN_OGLPOINTER_H
#define IRULAN_OGLPOINTER_H


namespace iru {
    template<typename T>
    class oglPointer {
        class RefCounter {
            friend class oglPointer;
            void inc() { count++; };
            void dec() { count--; };
            int get() { return count; };
            int count = 1;
        };

    public:
        oglPointer();
        oglPointer(const oglPointer<T>& obj);
        ~oglPointer();

        oglPointer& operator=(const oglPointer<T>& obj);
        unsigned int get() const { return id;};

    private:
        RefCounter* rc;
        unsigned int id = 0;
    };
}

#include "oglPointer.tpp"

#endif //IRULAN_OGLPOINTER_H
