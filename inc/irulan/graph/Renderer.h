#ifndef IRULAN_RENDERER_H
#define IRULAN_RENDERER_H

#include "RenderTarget.h"
#include "Descriptor.h"
#include <cstddef>

namespace iru {
    class Renderer {
        friend class App;

        struct RendererState {
            RenderTarget* target = nullptr;
            Descriptor* descriptor = nullptr;
        };
    public:
        void render(int first, int count);

        void setDescriptor(Descriptor* descriptor);
        void setRenderTarget(RenderTarget* target);

    private:
        Renderer();
        void* operator new(std::size_t sz) = delete;

        void bindDescriptor();
        void bindTarget();

        RendererState nextState;
        RendererState lastState;

    };
}

#endif //IRULAN_RENDERER_H
