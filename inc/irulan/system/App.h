#ifndef IRULAN_APP_H
#define IRULAN_APP_H

#include "irulan/math/Vector2.h"
#include "irulan/graph/Renderer.h"
#include "BufferAllocator.h"
#include "SDL2/SDL.h"
#include <string>
#include <unordered_map>

namespace iru {
    class App {
    public:
        int construct(Vector2i size, const std::string& title);

    protected:
        Renderer& renderer() { return rndr; };
        BufferAllocator& defaultAllocator() { return allc; };
        void close() { done = true; };
        void flip();

        int getKeyState(Uint8 key);
        int getLastKeyState(Uint8 key);
        Vector2i getMousePosition();
        void setMousePosition(const Vector2i& pos);

    private:
        Renderer rndr;
        BufferAllocator allc;
        std::string title;
        Vector2i size;
        Vector2i mousePosition;
        bool done = false;
        float ticks, accu;
        SDL_Window* window;
        SDL_GLContext context;
        SDL_Event event;
        std::unordered_map<Uint8, int> keyStates;
        std::unordered_map<Uint8, int> lastKeyStates;


        void constructWindow();
        int loop();
        virtual bool init() = 0;
        virtual bool logic(float delta) = 0;
        virtual bool render(float delta) = 0;
    };
}

#endif //IRULAN_APP_H
