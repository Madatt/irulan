#ifndef IRULAN_APP_H
#define IRULAN_APP_H

#include "irulan/math/Vector2.h"
#include "irulan/graph/Renderer.h"
#include "BufferAllocator.h"
#include "ResourceManager.h"
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
        ResourceManager& defaultRM() { return rm; };
        void close() { done = true; };
        void flip();

        int getKeyState(Uint8 key);
        int getLastKeyState(Uint8 key);
        Vector2i getMousePosition();
        Vector2i getMouseMove();
        void setMousePosition(const Vector2i& pos);
        Vector2i getWindowSize();
        void showCursor(bool show);

    private:
        Renderer rndr;
        BufferAllocator allc;
        ResourceManager rm;
        std::string title;
        Vector2i size;
        Vector2i mousePosition;
        Vector2i mouseMove;
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
