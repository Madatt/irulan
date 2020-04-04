#ifndef IRULAN_RENDERER_H
#define IRULAN_RENDERER_H

#include "RenderTarget.h"
#include "Descriptor.h"

namespace iru {
    class Renderer {
        friend class App;

        struct RendererState {
            RenderTarget* target = nullptr;
            Descriptor* descriptor = nullptr;
        };
    public:
        void setDescriptor(Descriptor& descriptor);
        void setRenderTarget(RenderTarget& target);

    private:
        Renderer();

        void bindDescriptor();
        void bindTarget();

        RendererState nextState;
        RendererState lastState;

    };
}

#endif //IRULAN_RENDERER_H
