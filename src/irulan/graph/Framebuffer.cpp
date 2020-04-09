#include "irulan/graph/Framebuffer.h"
#include "glad/glad.h"

namespace iru {
    void Framebuffer::bindColorTexture(Texture* tex, int n, int level) {
        glNamedFramebufferTexture(ptr.get(), GL_COLOR_ATTACHMENT0 + n, tex->ptr.get(), level);
    }

    void Framebuffer::bindDepthTexture(Texture* tex, int level) {
        glNamedFramebufferTexture(ptr.get(), GL_DEPTH_ATTACHMENT, tex->ptr.get(), level);
    }
}