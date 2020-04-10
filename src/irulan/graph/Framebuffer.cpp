#include "irulan/graph/Framebuffer.h"
#include "glad/glad.h"
#include <vector>

namespace iru {
    void Framebuffer::bindColorTexture(Texture* tex, int n, int level) {
        glNamedFramebufferTexture(ptr.get(), GL_COLOR_ATTACHMENT0 + n, tex->ptr.get(), level);
    }

    void Framebuffer::bindDepthTexture(Texture* tex, int level) {
        glNamedFramebufferTexture(ptr.get(), GL_DEPTH_ATTACHMENT, tex->ptr.get(), level);
    }

    void Framebuffer::attach(std::initializer_list<unsigned int> arr) {
        std::vector<unsigned int> tmp;
        for(auto& a : arr)
            tmp.push_back(GL_COLOR_ATTACHMENT0 + a);
        glNamedFramebufferDrawBuffers(ptr.get(), tmp.size(), tmp.data());
    }
}