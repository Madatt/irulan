#ifndef IRULAN_APP_H
#define IRULAN_APP_H

#include "irulan/math/Vector2.h"
#include "irulan/graph/Renderer.h"
#include "BufferAllocator.h"
#include "SDL2/SDL.h"
#include <string>

namespace iru {
    class App {
    public:
        int construct(Vector2i size, const std::string& title);

    protected:
        Renderer& renderer() { return rndr; };
        Buffer* newBuffer(unsigned int size);
        void close() { done = true; };

    private:
        Renderer rndr;
        BufferAllocator allc;
        std::string title;
        Vector2i size;
        bool done = false;
        float ticks, accu;
        SDL_Window* window;
        SDL_GLContext context;

        void constructWindow();
        int loop();
        virtual bool init() = 0;
        virtual bool logic(float delta) = 0;
        virtual bool render(float delta) = 0;
    };
}

#endif //IRULAN_APP_H
