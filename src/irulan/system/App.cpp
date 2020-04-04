#include "irulan/system/App.h"

namespace iru {
    App::App(Vector2i size, const std::string& title) {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        constructWindow();
        loop();
    }

    void App::constructWindow() {
        window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  size.x, size.y,
                                  SDL_WINDOW_OPENGL);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
        context = SDL_GL_CreateContext(window);
        if (context == nullptr) {
            close();
        }
    }

    void App::loop() {
        void init();
        while (!done) {
            //stub;
        }
    }
}