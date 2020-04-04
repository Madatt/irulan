#ifndef IRULAN_TRAITS_H
#define IRULAN_TRAITS_H

namespace iru::ogl {
    class Texture {
    public:
        static unsigned int alloc();
        static void free(unsigned int id);
    };

    class Shader {
    public:
        static unsigned int alloc();
        static void free(unsigned int id);
    };

    class VertexArray {
    public:
        static unsigned int alloc();
        static void free(unsigned int id);
    };

    class VertexBuffer {
    public:
        static unsigned int alloc();
        static void free(unsigned int id);
    };

    class Framebuffer {
    public:
        static unsigned int alloc();
        static void free(unsigned int id);
    };
}
#endif //IRULAN_TRAITS_H
