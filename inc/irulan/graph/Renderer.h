#ifndef IRULAN_RENDERER_H
#define IRULAN_RENDERER_H

#include "Framebuffer.h"
#include "Descriptor.h"
#include "Shader.h"
#include "Texture2D.h"
#include <cstddef>
#include <array>

namespace iru {
    class Renderer {
        friend class App;

        struct RendererState {
            Framebuffer* target = nullptr;
            Descriptor* descriptor = nullptr;
            Shader* shader = nullptr;
            std::array<Texture*, 16> textures = {};
        };
    public:
        void draw(int first, int count);
        void clearAll(Framebuffer* fb = nullptr, unsigned int layer = 0);

        void setDescriptor(Descriptor* descriptor);
        void setFramebuffer(Framebuffer* target);
        void setShader(Shader* shader);
        void setTexture(Texture* texture, int unit);

    private:
        Renderer();
        void* operator new(std::size_t sz) = delete;

        void bindDescriptor();
        void bindFramebuffer();
        void bindShader();
        void bindTextures();

        RendererState nextState;
        RendererState lastState;

    };
}

#endif //IRULAN_RENDERER_H
