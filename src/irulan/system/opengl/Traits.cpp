#include "irulan/system/opengl/Traits.h"
#include "glad/glad.h"

namespace iru::ogl {
    unsigned int Shader::alloc() {
        return glCreateProgram();
    }

    void Shader::free(unsigned int id) {
        if(id)
            glDeleteProgram(id);
    }

    unsigned int Texture::alloc() {
        unsigned int tmp;
        glCreateTextures(GL_TEXTURE_2D, 1, &tmp);
        return tmp;
    }

    void Texture::free(unsigned int id) {
        if(id)
            glDeleteTextures(1, &id);
    }

    unsigned int VertexArray::alloc() {
        unsigned int tmp;
        glCreateVertexArrays(1, &tmp);
        return tmp;
    }

    void VertexArray::free(unsigned int id) {
        if(id)
            glDeleteVertexArrays(1, &id);
    }

    unsigned int VertexBuffer::alloc() {
        unsigned int tmp;
        glCreateBuffers(1, &tmp);
        return tmp;
    }

    void VertexBuffer::free(unsigned int id) {
        if(id)
            glDeleteBuffers(1, &id);
    }

    unsigned int Framebuffer::alloc() {
        unsigned int tmp;
        glCreateFramebuffers(1, &tmp);
        return tmp;
    }

    void Framebuffer::free(unsigned int id) {
        if(id)
            glDeleteFramebuffers(1, &id);
    }
}