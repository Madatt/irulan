#ifndef IRULAN_RENDERER_H
#define IRULAN_RENDERER_H

#include "RenderTarget.h"
#include "Descriptor.h"
#include "Shader.h"
#include "Texture.h"
#include <cstddef>
#include <array>

namespace iru {
    class Renderer {
        friend class App;

        struct RendererState {
            RenderTarget* target = nullptr;
            Descriptor* descriptor = nullptr;
            Shader* shader = nullptr;
            std::array<Texture*, 16> textures = {};
        };
    public:
        void draw(int first, int count);

        void setDescriptor(Descriptor* descriptor);
        void setRenderTarget(RenderTarget* target);
        void setShader(Shader* shader);
        void setTexture(Texture* texture, int unit);

    private:
        Renderer();
        void* operator new(std::size_t sz) = delete;

        void bindDescriptor();
        void bindTarget();
        void bindShader();
        void bindTextures();

        RendererState nextState;
        RendererState lastState;

    };
}

#endif //IRULAN_RENDERER_H
